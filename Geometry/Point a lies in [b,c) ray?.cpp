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
    long double x=cy-by;
    long double y=bx-cx;
    long double c=-(bx-cx)*by+(by-cy)*bx;
    if(x*ax+y*ay+c!=0)
    {
        cout<<"NO";
        return 0;
    }
    if(!y)
    {
        if(by>=cy)
        {
            if(ay<=by)cout<<"YES";
            else cout<<"NO";
        }
        else
        {
            if(ay>=by)cout<<"YES";
            else cout<<"NO";
        } 
        return 0;
    }
    if(bx<=cx)
    {
        if(ax>=bx)cout<<"YES";
        else cout<<"NO";
    }
    else
    {
        if(ax<=bx)cout<<"YES";
        else cout<<"NO";
    }
    
    
}
