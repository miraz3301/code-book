#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
using namespace std;
vector<pair<ll,pair<ll,ll>>>graph;
void make_set(vector<ll>&parent,vector<ll>&rank,ll n)
{
    for(ll i=0;i<n+1;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}
ll ultimate_parent(vector<ll>&parent,ll node)
{
    if(parent[node]==node)return node;
    return parent[node]=ultimate_parent(parent,parent[node]);
}
void set_union(vector<ll>&parent,vector<ll>&rank,ll u,ll v)
{
    u=ultimate_parent(parent,u);
    v=ultimate_parent(parent,v);
    if(rank[v]>=rank[u])
    {
        parent[u]=v;
        if(rank[v]==rank[u])rank[v]++;
    }
    else parent[v]=u;
}
void kruskal_algorithm()
{
    ll n,e;
    cin>>n>>e;
    vector<pair<ll,pair<ll,ll>>>edg;
    for(ll i=0;i<e;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edg.push_back({c,{a,b}});
    }
    sort(edg.begin(),edg.end());
    vector<ll>parent(n+1),rank(n+1);
    make_set(parent,rank,n);
    ll min_wt=0,cnt=0;
    for(ll i=0;i<edg.size();i++)
    {
        ll u=ultimate_parent(parent,edg[i].second.first);
        ll v=ultimate_parent(parent,edg[i].second.second);
        if(v!=u)
        {
            min_wt+=edg[i].first;
            set_union(parent,rank,u,v);
            graph.push_back(edg[i]);
            cnt++;
        }
    }
    if(cnt!=n-1)cout<<"impossible";
    else cout<<min_wt;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    kruskal_algorithm();
}
