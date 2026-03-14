#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void rec(ll m,ll n,ll i,ll &sum,ll temp,vector<ll>&ans,vector<ll>&cur,vector<ll>arr)
{
    if(temp>m)return;
    if(temp>sum)
    {
        sum=temp;
        ans=cur;
    }
    if(i==n)return;
    cur.push_back(arr[i]);
    rec(m,n,i+1,sum,temp+arr[i],ans,cur,arr);
    cur.pop_back();
    rec(m,n,i+1,sum,temp,ans,cur,arr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    ll m,n;
    cin>>m>>n;
    vector<ll>ans,cur,arr(n);
    for(ll i=0;i<n;i++)cin>>arr[i];
    ll sum=0;
    rec(m,n,0,sum,0,ans,cur,arr);
    for(ll val:ans)cout<<val<<" ";
    cout<<"sum:"<<sum<<endl;
    
}
