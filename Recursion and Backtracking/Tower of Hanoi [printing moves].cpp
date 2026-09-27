#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void tower_of_hanoi(ll n,ll source,ll destination,ll auxiliary)
{
    if(n==1)
    {
        cout<<source<<" "<<destination<<endl;
        return;
    }
    tower_of_hanoi(n-1,source,auxiliary,destination);
    cout<<source<<" "<<destination<<endl;
    tower_of_hanoi(n-1,auxiliary,destination,source);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    tower_of_hanoi(n,1,3,2);
}
