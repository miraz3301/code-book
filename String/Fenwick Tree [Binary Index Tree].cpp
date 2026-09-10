struct BIT
{
    ll n;
    vector<ll>tree;
    BIT(ll _n=0)
    {
        n=_n;
        tree.assign(n+1,0);
    }
    void add(ll idx,ll val,ll mod) // update 
    {
        val%=mod;
        while(idx<=n)
        {
            tree[idx]+=val;
            if(tree[idx]>=mod)tree[idx]-=mod;
            if(tree[idx]<0)tree[idx]+=mod;
            idx+=idx&-idx;
        }
    }
    ll sum(ll idx,ll mod)  // for query
    {
        ll ans=0;
        while(idx>0)
        {
            ans+=tree[idx];
            if(ans>=mod)ans-=mod;
            idx-=idx&-idx;
        }
        return ans;
    }
    ll query(ll l,ll r,ll mod)
    {
        ll ans=sum(r,mod)-sum(l-1,mod);
        if(ans<0)ans+=mod;
        return ans;
    }
};
