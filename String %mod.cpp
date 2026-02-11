#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int stringMod(const string &s) 
{
    long long result = 0;  // use long long to prevent intermediate overflow
    for (char c : s)result = (result * 10 + (c - '0')) % MOD;
    return (int)result;
}
