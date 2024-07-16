#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ","
                     << " ";
            }
            cout << endl;
        }
    }

    // Kruskal's Algorithm || Disjoint Set || Union by Rank & Path Compression

    void makeSet(vector<int> &parent, vector<int> &rank, int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edgelist;

        for (int vertex_u = 0; vertex_u < V; vertex_u++)
        {
            for (auto edge : adj[vertex_u])
            {
                edgelist.push_back({edge[1], vertex_u, edge[0]});
            }
        }

        sort(edgelist.begin(), edgelist.end());
        vector<int> rank(V);
        vector<int> parent(V);

        makeSet(parent, rank, V);
        int minimumSpanningTree = 0;

        for (int i = 0; i < edgelist.size(); i++)
        {
            int u = findParent(parent, edgelist[i][1]);
            int v = findParent(parent, edgelist[i][2]);
            int wt = edgelist[i][0];

            if (u != v)
            {
                minimumSpanningTree += wt;
                unionSet(u, v, parent, rank);
            }
        }
        return minimumSpanningTree;
    }
};

int main()
{

    int n = 5; // number of nodes
    int m = 6; // number of edges

    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printGraph();

    // Kruskal's Algorithm

    return 0;
}

// Bridges in Graph

void dfs(int node, unordered_map<int, list<int>> &adj, int parent, int &timer, vector<int> &low, vector<int> &disc, unordered_map<int, bool> &vis, vector<vector<int>> &result)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, adj, node, timer, low, disc, vis, result);
            low[node] = min(low[node], low[nbr]);

            // Bridge present
            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            // back Edge case
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> low(v, -1);
    vector<int> disc(v, -1);

    unordered_map<int, bool> vis;

    int parent = -1;
    int timer = 0;

    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, parent, timer, low, disc, vis, result);
        }
    }
    return result;
}

void dfs(int node, unordered_map<int, list<int>> &adj, int parent, int &timer, vector<int> &low, vector<int> &disc, unordered_map<int, bool> &vis, vector<int> &ap)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, adj, node, timer, low, disc, vis, ap);
            low[node] = min(low[node], low[nbr]);

            // Check Ap or not
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            // back Edge case
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if (parent == -1 && child > 1)
        ap[node] = 1;
}

vector<vector<int>> findArticulationPoints(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> low(v, -1);
    vector<int> disc(v, -1);

    unordered_map<int, bool> vis;

    int parent = -1;
    int timer = 0;

    vector<int> ap(n, 0);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, parent, timer, low, disc, vis, ap);
        }
    }
    return result;
}

void dfs(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis, stack<int> &st)
{
    vis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(i, adj, vis, st);
        }
    }

    st.push(node);
}

void cntDFS(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
{
    vis[node] = true;

    for (auto nbr : transpose[node])
    {
        if (vis[nbr])
        {
            cntDFS(nbr, vis, transpose);
        }
    }
}

void KosarajusStronglyConnectedComponents(int v, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> vis;

    // First topological sort
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    // Create a transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // dfs call using above transpose
    int cnt = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!vis[top])
        {
            cnt++;
            cntDFS(top, vis, transpose);
        }
    }
    return cnt;
}

void bellmonFord(int n, int m, int src, int des, vector<vector<int>> edges)
{
    vector<int> dis(n + 1, 1e9);

    dis[src] = 0;

    // for applying n-1 times
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dis[u] != 1e9 && (dis[u] + wt < dis[v]))
            {
                dis[v] = dis[u] + wt;
            }
        }
    }

    // Check for negative cycle
    bool flag = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dis[u] != 1e9 && (dis[u] + wt < dis[v]))
        {
            flag = true;
            dis[v] = dis[u] + wt;
            break;
        }
    }
    if(!flag) return dis[des];
    return -1;
}