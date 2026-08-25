#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("bisector.in", "r", stdin);
    freopen("bisector.out", "w", stdout);

    ll a,b,c,d,e,f;   //A=(a,b) B=(c,d) C=(e,f)
    cin>>a>>b>>c>>d>>e>>f;

    long double u1_x=(c-a)/(sqrt((c-a)*(c-a)+(d-b)*(d-b)));
    long double u1_y=(d-b)/(sqrt((c-a)*(c-a)+(d-b)*(d-b)));
    long double u2_x=(e-a)/(sqrt((e-a)*(e-a)+(f-b)*(f-b)));
    long double u2_y=(f-b)/(sqrt((e-a)*(e-a)+(f-b)*(f-b)));
    long double bisector_x=u1_x+u2_x;
    long double bisector_y=u1_y+u2_y;

    long double A=-bisector_y;    // Ax + By +C = 0
    long double B=bisector_x;
    long double C=-(A*a+B*b);
    cout<<fixed<<setprecision(10)<<A<<" "<<B<<" "<<C;
}
