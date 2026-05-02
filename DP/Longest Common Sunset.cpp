#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<ll> Common_Subset(vector<ll>a,vector<ll>b)
{
    map<ll,ll>cnt1,cnt2;
    vector<ll>ans;
    for(auto x:a) cnt1[x]++;
    for(auto x:b) cnt2[x]++;
    for(auto it:cnt1)
    {
        ll val=it.first;
        ll freq=min(cnt1[val],cnt2[val]);
        while(freq--) ans.push_back(val);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    vector<ll>ans=Common_Subset(a,b);
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
}
