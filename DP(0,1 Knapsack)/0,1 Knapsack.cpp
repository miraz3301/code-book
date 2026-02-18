#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vector<pair<ll,ll>>wt_val(n+1);
    for(ll i=1;i<=n;i++)cin>>wt_val[i].first>>wt_val[i].second;

    ll cap;
    cin>>cap;
    ll dp[n+1][cap+1];
    for(ll i=0;i<=n;i++)for(ll j=0;j<=cap;j++)dp[i][j]=0;

    for(ll x=1;x<=n;x++)
    {
        for(ll y=1;y<=cap;y++)
        {
            if(y<wt_val[x].first)
            {
                dp[x][y]=dp[x-1][y];
            }
            else
            {
                    dp[x][y]=max(dp[x-1][y],dp[x-1][y-wt_val[x].first]+wt_val[x].second);
            }
        }
    }

    cout<<endl;
    /// printing the DP grid
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=cap;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    /// printing the selected items
    cout<<"Selected items: ";
    pair<ll,ll>pos={n,cap};
    ll q=n;
    while(q--)
    {
        pair<ll,ll>dum3={0,0};
        if(pos==dum3)break;
        pair<ll,ll>dum1={pos.first-1,pos.second};
        if(dp[pos.first][pos.second]==dp[dum1.first][dum1.second]) /// NEY NAI
        {
                pos= {pos.first-1,pos.second};
        }
        else /// NISE
        {
            cout<<"(item: "<<pos.first<<" value: "<<wt_val[pos.first].second<<")  ";
            pos={pos.first-1,pos.second-wt_val[pos.first].first};
        }
    }

}
/*

4
2 12
1 10
3 20
2 15
5
*/
