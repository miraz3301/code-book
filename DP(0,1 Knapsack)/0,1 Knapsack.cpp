#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n,cap;
    cin>>n>>cap;
    vector<pair<ll,ll>>wt_value(n+1);
    for(ll i=1;i<=n;i++)cin>>wt_value[i].first>>wt_value[i].second;

    ll dp[n+1][cap+1];
    for(ll i=0;i<=n;i++)for(ll j=0;j<=cap;j++)dp[i][j]=0;

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=cap;j++)
        {
            if(j<wt_value[i].first)dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt_value[i].first]+wt_value[i].second);
        }
    }
    cout<<dp[n][cap]<<endl;
    
    ll q=n;
    ll i=n,j=cap;
    while(q--)
    {
        if(!i or !j) break;
        if(dp[i][j]==dp[i-1][j]) i--;  // NEY NAI
        else                           // NISE
        {
            cout<<i<<"th item is taken. value: "<<wt_value[i].second<<endl;
            j-=wt_value[i].first;
            i--;
        }
    }
    

}
