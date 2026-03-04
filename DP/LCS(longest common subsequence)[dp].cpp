#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<vector<ll>>dp(1000,vector<ll>(1000,0));
ll LCS(string s1,string s2)
{
    ll n=s1.size();
    ll m=s2.size();

    for(ll i=0;i<=m;i++) dp[0][i]=0;
    for(ll i=0;i<=n;i++) dp[i][0]=0;

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    return dp[n][m];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin>>s1>>s2;

    cout<<LCS(s1,s2)<<endl;

}
