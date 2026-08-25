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
    long double bax=ax-bx;
    long double bay=ay-by;
    long double bcx=cx-bx;
    long double bcy=cy-by;
    // Dot product of BA and BC
    long double dot1=bax*bcx+bay*bcy;
    long double cax=ax-cx;
    long double cay=ay-cy;
    // Dot product of CA and BC
    long double dot2=cax*bcx+cay*bcy;
  
    if(dot1>0 and dot2<=0)
    {
        long double x=cy-by;
        long double y=bx-cx;
        long double c=-(bx-cx)*by+(by-cy)*bx;
        long double dis=abs(x*ax+y*ay+c)/sqrt(x*x+y*y);
        cout<<fixed<<setprecision(10)<<dis;
    }
    else
    {
        long double dis1=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        long double dis2=sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy));
        cout<<fixed<<setprecision(10)<<min(dis1,dis2);
    }
}
