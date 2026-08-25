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
    cin>>a1>>b1>>c1;
    long double a2,b2,c2;
    cin>>a2>>b2>>c2;
    long double y=(a1*c2-c1*a2)/(a2*b1-a1*b2);
    long double x=(b2*c1-b1*c2)/(a2*b1-a1*b2);
    cout<<fixed<<setprecision(10)<<x<<" "<<y;
    
}
