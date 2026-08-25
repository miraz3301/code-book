#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long double ax,ay,bx,by;
    cin>>ax>>ax>>bx>>by;
    long double dis=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    cout<<fixed<<setprecision(10)<<dis;
    
}
