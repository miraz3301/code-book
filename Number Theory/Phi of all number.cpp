#include<bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'
using namespace std;
const ll mx = 5000000;
ll phi[mx+1];
void phi_cal()
{
    for(ll i = 0; i <= mx; i++)phi[i] = i;

    for(ll i = 2; i <= mx; i++)
    {
        if(phi[i] == i)
        {
            for(ll j = i; j <= mx; j += i) phi[j] -= phi[j] / i;
        }
    }
}
