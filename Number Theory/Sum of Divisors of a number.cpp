#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod=1e9+7;
ll inv2=(mod+1)/2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n,sum=0;
    cin>>n;
    for(ll i=1;i<=n;)
    {
        ll k=n/i;
        ll l=i;
        ll r=n/k;
        ll cnt=(r-l+1)%mod;
        ll s=((l+r)%mod*cnt)%mod;
        s=(s*inv2)%mod;
        sum=(sum+s*k%mod)%mod;
        i=r+1;
    }
    cout<<sum;
}


// using sieve
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 500000;

    vector<long long> sumDiv(MAXN + 1, 0);

    for(int i = 1; i <= MAXN; i++){
        for(int j = 2*i; j <= MAXN; j += i){
            sumDiv[j] += i;
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << sumDiv[n] << "\n";
    }
}
