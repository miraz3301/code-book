#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
ll mod=10000007;
ll fn(ll n,vector<ll>&arr)
{
    if(arr[n]!=-1)return arr[n];
    return arr[n]=(fn(n-1,arr)+fn(n-2,arr)+fn(n-3,arr)+fn(n-4,arr)+fn(n-5,arr)+fn(n-6,arr))%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll T;
    cin>>T;
    for(ll t=1;t<=T;t++)
    {
        cout<<"Case "<<t<<": ";
        vector<ll>arr(10009,-1);
        for(ll i=0;i<6;i++)cin>>arr[i];
        ll n;
        cin>>n;
        cout<<(fn(n,arr)%mod)<<endl;
    }
}
