#define ll long long

const int N = 1e5 + 5;

vector<ll> graph[N];
bool vis[N];

void dfs(ll node)
{
    vis[node] = true;

    for (ll child : graph[node])
    {
        if (!vis[child])
            dfs(child);
    }
}
void bfs(ll src)
{
    queue<ll> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (ll child : graph[node])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Remove for directed graph
    }

    dfs(1);   // or bfs(1);
    for (ll i = 1; i <= n; i++)
    {
          if (!vis[i]) dfs(i);   // or bfs(i);
    }

    return 0;
}
