#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n, val;
    cin>>n>>val;
    vector<ll>c(n);
    unordered_map<ll,bool>mp;
    for(ll i=0;i<n;i++)
    {
        cin>>c[i];
        mp[c[i]]=true;
    }
    ll dp[val+1],ans[val+1]={0};
    dp[0]=1;
    for(ll i=1;i<=val;i++)
    {
        if(mp[i])
        {
            dp[i]=1;
            ans[i]=i;
            continue;
        }
        for(ll x:c)
        {
            if(i-x>=0)
            {
                if(dp[i-x])
                {
                    ans[i]=i-x;
                    dp[i]=1;
                    break;
                }
            }
        }

    }
    if(dp[val])
    {
        cout<<"possible: ";
        ll am=val;
        while(am>0)
        {
            if(am==ans[am])
            {
                cout<<am;
                break;
            }
            cout<<am-ans[am]<<" ";
            am=ans[am];
        }
    }
    else cout<<"impossible.";




    

}
