#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("distance1.in", "r", stdin);
    freopen("distance1.out", "w", stdout);

    ll a,b,x,y,c; // A(a,b) and Ax+By+C=0
    cin>>a>>b>>x>>y>>c;

    long double dis=abs(x*a+y*b+c)/sqrt(x*x+y*y);
    cout<<fixed<<setprecision(10)<<dis;
}
