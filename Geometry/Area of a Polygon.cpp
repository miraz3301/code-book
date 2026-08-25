#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;      //total number of arms
    cin>>n;
    ll x,y;    // first apex
    cin>>x>>y;
    vector<pair<ll,ll>>v(n-1);
    for(ll i=0;i<n-1;i++)
    {
        cin>>v[i].first>>v[i].second;    // rest of the apex
        v[i].first-=x;
        v[i].second-=y;
    }
    long double ans=0;
    for(ll i=0;i<n-2;i++)
    {
        long double a=v[i].first,b=v[i].second;
        long double c=v[i+1].first,d=v[i+1].second;
        ans+=a*d-b*c;
    }
    ans=abs(ans)/2;
    cout<<fixed<<setprecision(10)<<ans;
}
