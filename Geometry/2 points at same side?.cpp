/*
Input Format:
You’re given 7 integers which are the coordinates of the two points that do not lie on the line 
and the coefficients A B and C of the normal line.
Output Format:
Output “YES” (without quotes) if the two points lie on the same side of the line segment or 
“NO” (without quotes) otherwise.
*/
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long double a1,b1,c1;
    long double a2,b2,c2;
    long double bx,by,cx,cy;
    cin>>bx>>by>>cx>>cy;
    cin>>a2>>b2>>c2;
    a1=cy-by;
    b1=bx-cx;
    c1=-(bx-cx)*by+(by-cy)*bx;
    long double ay=(a1*c2-c1*a2)/(a2*b1-a1*b2);
    long double ax=(b2*c1-b1*c2)/(a2*b1-a1*b2);

    if(!b1)
    {
        if(by>cy)swap(by,cy);
        if(ay>=by and ay<=cy)cout<<"NO";
        else cout<<"YES";
        return 0;
    }
    if(bx>cx)swap(bx,cx);
    if(ax>=bx and ax<=cx)cout<<"NO";
    else cout<<"YES";
    
}
