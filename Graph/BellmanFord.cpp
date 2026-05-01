#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 100005;
const ll INF = 1e18;
ll dist[N];
vector<pair<pair<ll,ll>,ll>> graph;
bool BellmanFord(ll n, ll source)
{
    for(ll i = 1; i <= n; i++)dist[i] = INF;
    dist[source] = 0;
    for(ll i = 1; i <= n - 1; i++)
    {
        for(auto edge : graph)
        {
            ll u = edge.first.first;
            ll v = edge.first.second;
            ll w = edge.second;
            if(dist[u] != INF && dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }
    }

    for(auto edge : graph)
    {
        ll u = edge.first.first;
        ll v = edge.first.second;
        ll w = edge.second;
        if(dist[u] != INF && dist[v] > dist[u] + w) return false;
    }
    return true;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph.push_back({{u, v}, w});
    }
    ll source;
    cin >> source;
    if(BellmanFord(n, source)) for(ll i = 1; i <= n; i++) cout << dist[i] << " ";
    else cout << "No Solution";
}
