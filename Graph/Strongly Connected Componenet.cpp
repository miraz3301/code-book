#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
void dfs(vector<vector<int>>& graph, int u, stack<int>& st, vector<int>& vis)
{
    vis[u]=1;
    for(int v:graph[u])
    {
        if(vis[v]==0)
        {
            dfs(graph, v, st, vis);
        }
    }
    st.push(u);
}
void dfs2(vector<vector<int>>& graph, int u, vector<int>& scc, vector<int>& vis)
{
    vis[u]=1;
    scc.push_back(u);
    for(int v:graph[u])
    {
        if(vis[v]==0)
        {
            dfs2(graph, v, scc, vis);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>>graph(n), revGraph(n);
    for(int i=0;i<e;i++)
    {
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
    }

    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(graph, i, st, vis);
        }
    }
    
    vector<vector<int>> sccs;
    fill(vis.begin(), vis.end(), 0);
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(vis[u]==0)
        {
            vector<int>scc;
            dfs2(revGraph, u, scc, vis);
            sccs.push_back(scc);
        } 
    }
    cout<<sccs.size()<<"\n";

    for(auto v:sccs)
    {
        cout<<v.size()<<" ";
        for(auto x:v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
