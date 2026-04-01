#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool coloring(ll i,ll v,vector<vector<ll>>&adj,vector<ll>&color,ll m)
{
    if(i==v+1)return true;
    for(ll c=1;c<=m;c++)
    {
        bool f=true;
        for(ll r=0;r<=v;r++)
        {
            if(adj[i][r]==1 and color[r]==c)
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            color[i]=c;
            if(coloring(i+1,v,adj,color,m))return true;
            color[i]=-1;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,e;
    cin>>n>>e;
    vector<vector<ll>>adj(n+1,vector<ll>(n+1,0));
    for(ll i=0;i<e;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    ll c;
    cin>>c;
    vector<ll>color(n+1,-1);
    if(coloring(1,n,adj,color,c))
    {
        cout<<"Coloring is Possible\n";
        for(ll i=1;i<=n;i++)
        {
            cout<<"Node "<<i<<" : "<<color[i]<<endl;
        }
    }
    else cout<<"Coloring is not Possible\n";
}
/*
5 7  //number of nodes, number of edges
1 2
1 5
2 5
2 4
2 3
5 4
3 4
3    //number of colors
*/
