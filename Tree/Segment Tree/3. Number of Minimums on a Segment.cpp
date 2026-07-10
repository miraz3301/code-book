#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
using namespace std;
ll arr[100009];
vector<pair<ll,ll>>seg(500009);
void build_segTree(ll ind,ll left,ll right)
{
    if(left==right)
    {
        seg[ind].first=arr[left];
        seg[ind].second=1;
        return;
    }
    ll mid=(left+right)/2;
    build_segTree(2*ind,left,mid);
    build_segTree(2*ind+1,mid+1,right);
    seg[ind].first=min(seg[2*ind].first,seg[2*ind+1].first);
    if(seg[2*ind].first==seg[2*ind+1].first)seg[ind].second=seg[2*ind+1].second+seg[2*ind].second;
    else if(seg[2*ind].first<seg[2*ind+1].first)seg[ind].second=seg[2*ind].second;
    else seg[ind].second=seg[2*ind+1].second;
}
void update_segTree(ll ind,ll left,ll right,ll pos,ll val)
{
    if(pos<left||pos>right)return;
    if(left==right)
    {
        seg[ind].first=val;
        seg[ind].second=1;
        return;
    }
    ll mid=(left+right)/2;
    update_segTree(2*ind,left,mid,pos,val);
    update_segTree(2*ind+1,mid+1,right,pos,val);
    seg[ind].first=min(seg[2*ind].first,seg[2*ind+1].first);
    if(seg[2*ind].first==seg[2*ind+1].first)seg[ind].second=seg[2*ind+1].second+seg[2*ind].second;
    else if(seg[2*ind].first<seg[2*ind+1].first)seg[ind].second=seg[2*ind].second;
    else seg[ind].second=seg[2*ind+1].second;
}
ll seg_min(ll ind,ll left,ll right,ll b,ll e)
{
    if(left>=b&&right<=e)return seg[ind].first;
    if(b>right||e<left)return LLONG_MAX;
    ll mid=(left+right)/2;
    ll ans1=seg_min(2*ind,left,mid,b,e);
    ll ans2=seg_min(2*ind+1,mid+1,right,b,e);
    return min(ans1,ans2);
}
ll seg_min_cnt(ll ind,ll left,ll right,ll b,ll e,ll mn)
{
    if(b>right||e<left)return 0;
    // if(left==right&&seg[ind].first==mn)return seg[ind].second;
    // if(left==right&&seg[ind].first!=mn)return 0;
    if((left>=b&&right<=e)&&seg[ind].first==mn)return seg[ind].second;
    if((left>=b&&right<=e)&&seg[ind].first!=mn)return 0;
    ll mid=(left+right)/2;
    ll ans1=seg_min_cnt(2*ind,left,mid,b,e,mn);
    ll ans2=seg_min_cnt(2*ind+1,mid+1,right,b,e,mn);
    return ans1+ans2;
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
            ll mn=seg_min(1,1,n,l+1,r);
            cout<<mn<<" "<<seg_min_cnt(1,1,n,l+1,r,mn)<<endl;
        }
    }
}
