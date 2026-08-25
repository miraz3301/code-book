#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long double bx,by,cx,cy;
    cin>>bx>>by>>cx>>cy;
    long double x=cy-by;
    long double y=bx-cx;
    long double c=-(bx-cx)*by+(by-cy)*bx;
    cout<<fixed<<setprecision(10)<<x<<" "<<y<<" "<<c;
}
