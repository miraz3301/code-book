/*
        A ring is composed of n (even number) circles.
        Put natural numbers 1, 2, . . . , n into each circle separately, and the
        sum of numbers in two adjacent circles should be a prime.
        Note: the number of first circle should always be 1.
        examples:
        when n=8 rings are:
        1 2 3 8 5 6 7 4
        1 2 5 8 3 4 7 6
        1 4 7 6 5 8 3 2
        1 6 7 4 3 8 5 2
  */

ll n;
vector<ll>v;
vector<bool>prime(40),used(20);
void solve()
{
    if(v.size()==n)
    {
        if(prime[v[n-1]+v[0]])
        {
            for(ll x:v)cout<<x<<" ";
            cout<<endl;
        }
        return;
    }

    for(ll i=2;i<=n;i++)
    {
        if(!used[i] && prime[v.back()+i])
        {
            used[i]=true;
            v.push_back(i);
            solve();
            v.pop_back();
            used[i]=false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll tc=1;
    for(ll x:{2,3,5,7,11,13,17,19,23,29,31})prime[x]=true;
    while(cin>>n)
    {
        cout<<"Case "<<tc++<<":\n";
        v.clear();
        used.clear();
        v.push_back(1);
        used[1]=true;
        solve();
    }
}
