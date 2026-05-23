//how many times the prime number p appears in the factorization of n!
int legendre(int n, int p)
{
    int cnt = 0;
    while (n)
    {
        n /= p;
        cnt += n;
    }
    return cnt;
}
