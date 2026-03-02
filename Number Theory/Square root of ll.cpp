#include<bits/stdc++.h>
using namespace std;

#define ll long long
int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  ll n; 
  cin >> n;
  ll root = sqrtl(n);
  while (root * root < n) ++root;
  while (root * root > n) --root;
  
  cout << root << '\n';
  return 0;
}
