#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
using namespace std;
ll mx=1e6;
vector<ll>v(1000001);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(ll i=1;i<=mx;i++)
    {
        for(ll j=i;j<=mx;j+=i)
        {
            v[j]++;
        }
    }
    ll T;
    cin>>T;
    while(T--)
    {
        ll x;
        cin>>x;
        cout<<v[x]<<endl;
    }
}
