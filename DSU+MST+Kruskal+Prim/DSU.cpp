#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll par[200009],rk[200009]={0};
ll ultimate_pa(ll a)
{
    if(par[a]==a)return a;
    return par[a]=ultimate_pa(par[a]);
}
void make_set(ll a,ll b)
{
    ll p_a=ultimate_pa(a);
    ll p_b=ultimate_pa(b);
    if(p_a==p_b) return;
    if(rk[p_a]>rk[p_b])par[p_b]=p_a;
    else if(rk[p_a]<rk[p_b])par[p_a]=p_b;
    else
    {
        par[p_a]=p_b;
        rk[p_b]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n,e;
    cin>>n>>e;
    for(ll i=0;i<=n;i++)par[i]=i;
    for(ll i=0;i<e;i++)
    {
        ll a,b;
        cin>>a>>b;
        make_set(a,b);
    }
}
