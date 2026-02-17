long long countDivisible(long long n, long long m, long long l, long long r) 
{
    long long g = __gcd(n, m);

    // compute LCM safely
    __int128 L = (__int128)(n / g) * m;

    if (L > r) return 0LL;

    return (long long)(r / L) - (long long)((l - 1) / L);
}
