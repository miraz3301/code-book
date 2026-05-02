#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<vector<ll>>dp(1005,vector<ll>(1005,0));
ll LCSubstring(string s1,string s2)
{
    ll n=s1.size();
    ll m=s2.size();
    ll mx=0;
    for(ll i=0;i<=n;i++) dp[i][0]=0;
    for(ll j=0;j<=m;j++) dp[0][j]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                mx=max(mx,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return mx;
}

string Print_LCSubstring(string s1,string s2)
{
    ll n=s1.size();
    ll m=s2.size();
    ll len=0,pos=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(dp[i][j]>len)
            {
                len=dp[i][j];
                pos=i;
            }
        }
    }
    string ans="";
    for(ll i=pos-len;i<pos;i++) ans+=s1[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin>>s1>>s2;
    cout<<LCSubstring(s1,s2)<<endl;
    cout<<Print_LCSubstring(s1,s2)<<endl;
}
