#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
using namespace std;
ll arr[100009],seg[500009];
void build_segTree(ll ind,ll left,ll right)
{
    if(left==right)
    {
        seg[ind]=arr[left];
        return;
    }
    ll mid=(left+right)/2;
    build_segTree(2*ind,left,mid);
    build_segTree(2*ind+1,mid+1,right);
    seg[ind]=min(seg[2*ind],seg[2*ind+1]);
}
void update_segTree(ll ind,ll left,ll right,ll pos,ll val)
{
    if(pos<left||pos>right)return;
    if(left==right)
    {
        seg[ind]=val;
        return;
    }
    ll mid=(left+right)/2;
    update_segTree(2*ind,left,mid,pos,val);
    update_segTree(2*ind+1,mid+1,right,pos,val);
    seg[ind]=min(seg[2*ind],seg[2*ind+1]);
}
ll seg_min(ll ind,ll left,ll right,ll b,ll e)
{
    if(left>=b&&right<=e)return seg[ind];
    if(b>right||e<left)return LLONG_MAX;
    ll mid=(left+right)/2;
    ll ans1=seg_min(2*ind,left,mid,b,e);
    ll ans2=seg_min(2*ind+1,mid+1,right,b,e);
    return min(ans1,ans2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)cin>>arr[i];
    build_segTree(1,1,n);
    while(q--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll pos,val;
            cin>>pos>>val;
            update_segTree(1,1,n,pos+1,val);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            cout<<seg_min(1,1,n,l+1,r)<<endl;
        }
    }
}
