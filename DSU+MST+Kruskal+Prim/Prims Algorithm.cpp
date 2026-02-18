#include<bits/stdc++.h>
using namespace std;
int spanningTree(int st,int V,vector<vector<int>>adj[]) 
{
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited(V, false);
    int res = 0;
    pq.push({0,st});
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int wt = p.first;
        int u = p.second;
        if(visited[u])continue;
        res += wt;
        visited[u] = true;
        for(auto &v : adj[u])
        {
            if(!visited[v[0]])pq.push({v[1], v[0]});
        }
    }
    return res;
}
int spanningTree2(int st, int V, vector<vector<int>> adj[], vector<pair<int,int>> &mstEdges) 
{
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    vector<bool> visited(V, false);
    int res = 0;
    pq.push({0, st, -1}); // weight, node, parent
    while(!pq.empty()) 
    {
        auto [wt, u, parent] = pq.top();
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        res += wt;
        if(parent != -1) mstEdges.push_back({parent, u});
        for(auto &v : adj[u]) if(!visited[v[0]]) pq.push({v[1], v[0], u});
    }
    return res;
}
int main()
{
    int V = 3;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    cout << spanningTree(0,V, adj) << endl;
}
