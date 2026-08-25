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
    
    long double ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    ax-=bx;
    ay-=by;
    cx-=bx;
    cy-=by;
    bx-=bx;
    by-=by;
    long double ans1=atan2(ay,ax);
    if(ans1<0)ans1+=2*acos(-1.0);
    long double ans2=atan2(cy,cx);
    if(ans2<0)ans2+=2*acos(-1.0);
    long double ans=min(abs(ans1-ans2),2.00*acos(-1.0)-abs(ans1-ans2));
    if(ans<=acos(-1.0)/2)
    {
        long double x=cy-by;
        long double y=bx-cx;
        long double c=-(bx-cx)*by+(by-cy)*bx;
        long double dis=abs(x*ax+y*ay+c)/sqrt(x*x+y*y);
        cout<<fixed<<setprecision(10)<<dis;
    }
    else
    {
        long double dis=sqrt(ax*ax+ay*ay);
        cout<<fixed<<setprecision(10)<<dis;
    }
}








2.
#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    // Create vectors BA and BC
    long double bax = ax - bx;
    long double bay = ay - by;
    long double bcx = cx - bx;
    long double bcy = cy - by;

    // Dot product of BA and BC
    long double dot = bax * bcx + bay * bcy;

    if (dot <= 0) 
    {
        // Angle is obtuse or 90 degrees. Projection is behind B.
        // The closest point on the ray is B itself.
        long double dis = sqrt(bax * bax + bay * bay);
        cout << fixed << setprecision(10) << dis << '\n';
    } 
    else 
    {
        // Projection falls on the ray.
        // Use 2D cross product to find the perpendicular distance.
        long double cross_mag = abs(bax * bcy - bay * bcx);
        long double bc_len = sqrt(bcx * bcx + bcy * bcy);
        long double dis = cross_mag / bc_len;
        cout << fixed << setprecision(10) << dis << '\n';
    }
    
    return 0;
}
