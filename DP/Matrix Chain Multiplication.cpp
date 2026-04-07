#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void print(ll i,ll j,vector<vector<ll>>&T)
{
    if(i==j)
    {
        cout<<"A"+to_string(i);
        return;
    }
    cout<<"(";
    print(i,T[i][j],T);
    print(T[i][j]+1,j,T);
    cout<<")";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)cin>>arr[i]; 
    vector<vector<ll>>dp(n,vector<ll>(n,-1));
    vector<vector<ll>>T(n,vector<ll>(n,-1));

    n--;
    for(ll i=0;i<=n;i++)dp[i][i]=0;

    for(ll l=2;l<=n;l++)
    {
        for(ll i=1;i<=n-l+1;i++)
        {
            ll j=l+i-1;
            ll res=LLONG_MAX;
            for(ll k=i;k<j;k++)
            {
                ll cur=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(res>cur)
                {
                    res=cur; 
                    T[i][j]=k;
                }
            }
            dp[i][j]=res;

        }
    }
    cout<<dp[1][n]<<endl;
    print(1,n,T);
}
