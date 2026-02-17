#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
const int N = 50000;
int spf[N + 1];
unordered_map<ll, vector<pair<ll, ll>>> mp_pf;
void PF()
{
    for (int i = 1; i <= N; i++)spf[i] = i;
    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)if (spf[j] == j)spf[j] = i;
        }
    }
    for (int f = 2; f <= N; f++)
    {
        int x = f;
        while (x > 1)
        {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0)
            {
                x /= p;
                cnt++;
            }
            mp_pf[f].push_back({p, cnt});
        }
    }
}
