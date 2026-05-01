#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 100005;
const ll INF = 1e18;
vector<pair<ll,ll>> graph[N];
ll dist[N];
bool visited[N];

void dijkstra(ll source, ll n)
{
    for(ll i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while(!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto edge : graph[u])
        {
            ll v = edge.first;
            ll w = edge.second;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    ll source;
    cin >> source;
    dijkstra(source, n);
    for(ll i = 1; i <= n; i++)
    {
        cout << "Distance to " << i << " = " << dist[i] << endl;
    }
}
