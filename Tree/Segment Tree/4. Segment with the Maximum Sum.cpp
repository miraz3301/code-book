#include <bits/stdc++.h>
#define ll long long int
#define ld long long double
using namespace std;
class pp
{
    public:
    ll sum,pref,suff,ans;
};
ll arr[100009];
pp seg[500009];
void build_segTree(ll ind, ll left, ll right)
{
    if (left == right)
    {
        seg[ind].sum = arr[left];
        seg[ind].pref = max(arr[left],0LL);
        seg[ind].suff = max(arr[left], 0LL);
        seg[ind].ans = max(arr[left], 0LL);
        return;
    }
    ll mid = (left + right) / 2;
    build_segTree(2 * ind, left, mid);
    build_segTree(2 * ind + 1, mid + 1, right);
    seg[ind].sum = seg[2 * ind].sum + seg[2 * ind + 1].sum;
    seg[ind].pref = max(seg[2 * ind].pref, seg[2 * ind].sum + seg[2 * ind + 1].pref);
    seg[ind].suff = max(seg[2 * ind + 1].suff, seg[2 * ind + 1].sum + seg[2 * ind].suff);
    seg[ind].ans = max({seg[2 * ind].ans, seg[2 * ind + 1].ans, seg[2 * ind].suff + seg[2 * ind + 1].pref});
}
void update_segTree(ll ind, ll left, ll right, ll pos, ll val)
{
    if (pos < left || pos > right) return;
    if (left == right)
    {
        
        seg[ind].sum= val;
        seg[ind].pref = max(val, 0LL);
        seg[ind].suff = max(val, 0LL);
        seg[ind].ans = max(val, 0LL);
        return;
    }
    ll mid = (left + right) / 2;
    update_segTree(2 * ind, left, mid, pos, val);
    update_segTree(2 * ind + 1, mid + 1, right, pos, val);
    seg[ind].sum = seg[2 * ind].sum + seg[2 * ind + 1].sum;
    seg[ind].pref = max(seg[2 * ind].pref, seg[2 * ind].sum + seg[2 * ind + 1].pref);
    seg[ind].suff = max(seg[2 * ind + 1].suff, seg[2 * ind + 1].sum + seg[2 * ind].suff);
    seg[ind].ans = max({seg[2 * ind].ans, seg[2 * ind + 1].ans, seg[2 * ind].suff + seg[2 * ind + 1].pref});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> arr[i];
    build_segTree(1, 1, n);
    cout<<seg[1].ans<<endl;
    while (q--)
    {
        
            ll pos, val;
            cin >> pos >> val;
            update_segTree(1, 1, n, pos + 1, val);
            cout << seg[1].ans << endl;
    }
}
