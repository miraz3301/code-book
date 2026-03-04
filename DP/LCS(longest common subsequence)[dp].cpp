#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<vector<ll>>dp(1000,vector<ll>(100,0));
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
string Print_LCS(string s1,string s2)
{
    ll len=LCS(s1,s2);
    string ans;
    ll q=s1.size()+s2.size();
    pair<ll,ll>cur_pos={s1.size(),s2.size()};
    while(q--)
    {
        //cout<<cur_pos.first<<" "<<cur_pos.second<<endl;
        if(!cur_pos.first or !cur_pos.second)break;
        if(dp[cur_pos.first][cur_pos.second]!=max(dp[cur_pos.first-1][cur_pos.second],dp[cur_pos.first][cur_pos.second-1]))
        {
            ans+=s1[cur_pos.first-1];
            cur_pos={cur_pos.first-1,cur_pos.second-1};
        }
        else if(dp[cur_pos.first][cur_pos.second]==dp[cur_pos.first-1][cur_pos.second]) cur_pos={cur_pos.first-1,cur_pos.second};
        else cur_pos={cur_pos.first,cur_pos.second-1};
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin>>s1>>s2;

    cout<<Print_LCS(s1,s2)<<endl;

}
