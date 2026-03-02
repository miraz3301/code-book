long long mod = 1e9+7;
long long power(long long a, long long b) 
{
    long long res = 1;
    while(b) 
    {
        if(b & 1) res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}

long long modInverse(long long b) 
{
    return power(b, mod - 2);  // only if mod is prime
}

long long divide_Mod(long long A, long long B)
{
    return (__int128)A * modInverse(B) % mod;
}
long long multiplied_Mod(long long A, long long B)
{
    return ((__int128)A * B) % mod;
}
