#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long double a,b,c,r;
    cin>>a>>b>>c>>r;
    long double c2=r*(sqrt(a*a+b*b));
    cout<<fixed<<setprecision(10)<<a<<" "<<b<<" "<<c2+c<<endl;
    cout<<fixed<<setprecision(10)<<a<<" "<<b<<" "<<-c2+c;
}
