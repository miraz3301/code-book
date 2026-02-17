#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll blockSize = sqrt(n);
    ll numBlocks = (n + blockSize - 1) / blockSize;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++)cin >> arr[i];
    vector<ll> blockMax(numBlocks, LLONG_MIN);
    for(ll i = 0; i < n; i++)blockMax[i / blockSize] = max(blockMax[i / blockSize], arr[i]);
    ll q;
    cin >> q;
    while(q--)
    {
        ll l, r;
        cin >> l >> r;   // assume 0-based indexing
        ll mx = LLONG_MIN;
        while(l <= r)
        {
            if(l % blockSize == 0 && l + blockSize - 1 <= r)
            {
                mx = max(mx, blockMax[l / blockSize]);
                l += blockSize;
            }
            else
            {
                mx = max(mx, arr[l]);
                l++;
            }
        }
        cout << mx << "\n";
    }
}
