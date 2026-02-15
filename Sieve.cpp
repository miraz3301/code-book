#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
bool f[N];
int32_t main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n = N - 9;
  vector<int> primes;
  f[1] = true;
  for (int i = 2; i * i < N; i++) 
    {
        if (!f[i]) 
        {
            for (int j = i * i; j < N; j += i)f[j] = true;
        }
    }
  cout << primes.size() << '\n';
  return 0;
}
