#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod=1e9+7;
ll inv2=(mod+1)/2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n,sum=0;
    cin>>n;
    for(ll i=1;i<=n;)
    {
        ll k=n/i;
        ll l=i;
        ll r=n/k;
        ll cnt=(r-l+1)%mod;
        ll s=((l+r)%mod*cnt)%mod;
        s=(s*inv2)%mod;
        sum=(sum+s*k%mod)%mod;
        i=r+1;
    }
    cout<<sum;
}
