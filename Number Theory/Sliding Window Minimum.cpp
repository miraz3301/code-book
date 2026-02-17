#include<bits/stdc++.h>
#define ll long long
using namespace std;
deque<pair<ll,ll>>st;
vector<ll>arr(10000009);
void insert_back(ll i,ll x)
{
    if(st.empty())st.push_back({i,x});
    else if(st.back().second<=x)st.push_back({i,x});
    else
    {
        while(!st.empty())
        {
            if(st.back().second<=x)break;
            else st.pop_back();
        }
        st.push_back({i,x});
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++)cin>>arr[i];
    for(ll i=0;i<k;i++)
    {
        insert_back(i,arr[i]);
    }
    ll ans=st.front().second;
    for(ll i=1;i+k<=n;i++)
    {
        while(!st.empty()&&st.front().first<i)st.pop_front();
        insert_back(i+k-1,arr[i+k-1]);
        ans^=st.front().second;
    }
    cout<<ans;
}
