// lpf(x) → least prime factor

// gpf(x) → greatest prime factor

// ω(x) → number of distinct prime factors

// Ω(x) → total number of prime factors (with multiplicity)

// d(x) → number of divisors

// σ(x) → sum of divisors
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e6 + 5;   // adjust based on constraints
ll lpf[MAXN];

void sieve() 
{
    for(ll i = 2; i < MAXN; i++) 
    {
        if(lpf[i] == 0) 
        {
            for(ll j = i; j < MAXN; j += i) if(lpf[j] == 0) lpf[j] = i;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n;
    cin >> n;

    while(n--) 
    {
        ll x;
        cin >> x;

        if(x == 1) 
        {
            cout << "1 1 0 0 1 1\n";
            continue;
        }

        ll temp = x;
        ll least = lpf[x];
        ll greatest = 0;
        ll distinct = 0;
        ll total_pf = 0;
        ll divisors = 1;
        ll sum_div = 1;

        while (temp > 1) 
        {
            ll prime = lpf[temp];
            ll count = 0;

            while (temp % prime == 0) 
            {
                temp /= prime;
                count++;
            }
            greatest = prime;
            distinct++;
            total_pf += count;
            divisors *= (count + 1);
            // geometric series formula for sum of divisors
            ll term = 1;
            ll power = 1;
            for (int i = 0; i < count; i++) 
            {
                power *= prime;
                term += power;
            }
            sum_div *= term;
        }

        cout << least << " "
             << greatest << " "
             << distinct << " "
             << total_pf << " "
             << divisors << " "
             << sum_div << "\n";
    }

    return 0;
}
