import asyncio
from playwright.async_api import async_playwright
from urllib.parse import urljoin, urlparse
import os
import re

async def scrape_with_playwright(url: str):
    async with async_playwright() as p:
        browser = await p.chromium.launch()
        page = await browser.new_page()
        await page.goto(url, wait_until='networkidle')
        html = await page.content()
        base_url = url

        # Collect all asset URLs (img, link, script, etc.)
        asset_urls = set()
        # Images
        for img in await page.query_selector_all('img'):
            src = await img.get_attribute('src')
            if src:
                asset_urls.add(urljoin(base_url, src))
        # Stylesheets
        for link in await page.query_selector_all('link[rel="stylesheet"]'):
            href = await link.get_attribute('href')
            if href:
                asset_urls.add(urljoin(base_url, href))
        # Scripts
        for script in await page.query_selector_all('script[src]'):
            src = await script.get_attribute('src')
            if src:
                asset_urls.add(urljoin(base_url, src))
        # SVGs (inline SVGs are in HTML, external SVGs are in <img> or <object>)
        for obj in await page.query_selector_all('object[data]'):
            data = await obj.get_attribute('data')
            if data and data.endswith('.svg'):
                asset_urls.add(urljoin(base_url, data))
        # Favicon
        for link in await page.query_selector_all('link[rel~="icon"]'):
            href = await link.get_attribute('href')
            if href:
                asset_urls.add(urljoin(base_url, href))

        await browser.close()
        return {
            'html': html,
            'assets': list(asset_urls)
        } 