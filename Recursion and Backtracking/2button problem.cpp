#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
vector<ll>ans;
ll f=false;
void fun(ll x,ll y)
{
    if(x>y||f)return;
    ans.push_back(x);
    if(x==y)
    {
        f=true;
        return;
    }
    fun(2*x,y);
    fun(10*x+1,y);
    if(!f)ans.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll x,y;
    cin>>x>>y;
    fun(x,y);
    if(!f)cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        cout<<ans.size()<<endl;
        for(ll val:ans)cout<<val<<" ";
    } 
}
