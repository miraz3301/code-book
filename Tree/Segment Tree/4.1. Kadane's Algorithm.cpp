long long cur = 0;
long long ans = 0;   //if the problem allows an empty subarray; else a[0]

for (int i = 0; i < n; i++)
{
    cur += a[i];
    ans = max(ans, cur);
    if (cur < 0) cur = 0;
}

cout << ans << '\n';
