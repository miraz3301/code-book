#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;/// number of coins
    vector<ll>c(n);
    map<ll,ll>mp;
    for(ll i=0;i<n;i++)
    {
        cin>>c[i];
        mp[c[i]]=1;
    }

    ll val;/// amount to build (max val)
    cin>>val;
    ll dp[val+1];
    dp[0]=1;

    for(ll i=1;i<=val;i++)
    {
        if(mp[i])dp[i]=1;
        else
        {
            ll ans=0;
            for(ll x:c)
            {
                if((i-x)>=0)ans|=dp[i-x];
                ///else ans|=0;
            }
            dp[i]=ans;
        }
    }
    for(ll i=0;i<=val;i++)
    {
        cout<<"("<<i<<" : "<<dp[i]<<")\n";
    }


}
/*

3       (number of coins)
4 7 10  (coins)
15      (amount to build)
*/

