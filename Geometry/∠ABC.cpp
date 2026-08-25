1.
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("angle2.in", "r", stdin);
    freopen("angle2.out", "w", stdout);

    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    long double ans1=atan2(b,a);
    if(ans1<0)ans1+=2*acos(-1.0);
    long double ans2=atan2(d,c);
    if(ans2<0)ans2+=2*acos(-1.0);
    long double ans=min(abs(ans1-ans2),2.00*acos(-1.0)-abs(ans1-ans2));
    cout<<fixed<<setprecision(10)<<ans;
}

2.
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    // BA = A - B
    double bax = ax - bx;
    double bay = ay - by;

    // BC = C - B
    double bcx = cx - bx;
    double bcy = cy - by;

    double dot = bax * bcx + bay * bcy;

    double lenBA = sqrt(bax * bax + bay * bay);
    double lenBC = sqrt(bcx * bcx + bcy * bcy);

    double angle = acos(dot / (lenBA * lenBC));

    // radians -> degrees
    angle = angle * 180.0 / acos(-1.0);

    cout << fixed << setprecision(10) << angle << '\n';
}
