import sys
import asyncio

if sys.platform.startswith("win"):
    asyncio.set_event_loop_policy(asyncio.WindowsSelectorEventLoopPolicy())

from fastapi import FastAPI, HTTPException, Request
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import FileResponse
from fastapi.staticfiles import StaticFiles
from pydantic import BaseModel, HttpUrl
from typing import Optional
import uvicorn
import os
import re
import requests
from urllib.parse import urlparse
from .scraper import get_website_data
from .llm_service import llm_service
from .playwright_scraper import scrape_with_playwright

app = FastAPI(title="Website Cloning Service")

# Serve static assets
assets_dir = os.path.join(os.path.dirname(__file__), '..', 'assets')
os.makedirs(assets_dir, exist_ok=True)
app.mount("/assets", StaticFiles(directory=assets_dir), name="assets")

# Configure CORS
app.add_middleware(
    CORSMiddleware,
    allow_origins=["http://localhost:3000"],  # Frontend URL
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

class WebsiteURL(BaseModel):
    url: HttpUrl

class CloneResponse(BaseModel):
    html: str
    message: Optional[str] = None

@app.get("/")
async def root():
    return {"message": "Website Cloning Service API"}

@app.post("/clone", response_model=CloneResponse)
async def clone_website(website: WebsiteURL):
    try:
        # Step 1: Scrape the website
        website_data = get_website_data(str(website.url))
        
        # Step 2: Generate the clone using LLM
        cloned_html = await llm_service.generate_website_clone(website_data)
        
        return CloneResponse(
            html=cloned_html,
            message="Website cloned successfully"
        )
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))

# --- New endpoint for full clone with assets ---
@app.post("/clone_full", response_model=CloneResponse)
async def clone_full_website(website: WebsiteURL):
    try:
        # 1. Scrape with Playwright
        result = await scrape_with_playwright(str(website.url))
        html = result['html']
        assets = result['assets']

        # 2. Download assets
        parsed = urlparse(website.url)
        domain = parsed.netloc.replace(':', '_')
        asset_folder = os.path.join(assets_dir, domain)
        os.makedirs(asset_folder, exist_ok=True)
        asset_map = {}
        for asset_url in assets:
            try:
                filename = re.sub(r'[^a-zA-Z0-9._-]', '_', os.path.basename(asset_url.split('?')[0]))
                if not filename:
                    continue
                local_path = os.path.join(asset_folder, filename)
                # Download asset if not already present
                if not os.path.exists(local_path):
                    r = requests.get(asset_url, timeout=10)
                    if r.ok:
                        with open(local_path, 'wb') as f:
                            f.write(r.content)
                # Map original URL to local static path
                asset_map[asset_url] = f"/assets/{domain}/{filename}"
            except Exception as e:
                print(f"Failed to download asset {asset_url}: {e}")

        # 3. Rewrite HTML to use local asset paths
        def replace_asset_urls(match):
            url = match.group(2)
            return f'{match.group(1)}"{asset_map.get(url, url)}"'
        html = re.sub(r'(src|href)="([^"]+)"', replace_asset_urls, html)

        return CloneResponse(
            html=html,
            message="Website cloned with assets"
        )
    except Exception as e:
        print(f"/clone_full error: {e}")
        raise HTTPException(status_code=500, detail=str(e))

if __name__ == "__main__":
    uvicorn.run("main:app", host="0.0.0.0", port=8000, reload=True)
