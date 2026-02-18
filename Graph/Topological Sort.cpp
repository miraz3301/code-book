//Topological Sorting Using DFS
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
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<e;i++)
    {
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }

    stack<int>st;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(graph, i, st, vis);
        }
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}


//Topological Sort using BFS (Kahn’s Algorithm)
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n,e;

    cin>>n>>e;
    vector<vector<int>>graph(n+1);
    vector<int>indegrees(n+1,0);
    for(int i=0;i<e;i++)
    {
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        indegrees[v]++;
    }
    /*
    for(int i=0;i<n;i++){
        cout<<i<<"-> "<<indegrees[i]<<endl;
    }
    */
    queue<int>q;
    vector<int>res;
    for(int i=1;i<=n;i++)
    {
      if(indegrees[i]==0) q.push(i);
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        // cout<<u<<" ";
        res.push_back(u);
        for(int v:graph[u])
        {
            indegrees[v]--;
            if(indegrees[v]==0) q.push(v);
        }
    
    }

    for(int val:res)
    {
        cout<<val<<" ";
    }
    cout<<"\n";   
}

