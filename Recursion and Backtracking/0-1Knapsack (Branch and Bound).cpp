#include<bits/stdc++.h>
#define ll long long int
#define value second.first
#define weight second.second
#define per_unit first
using namespace std;

int main()
{
    ll n;
    cin>>n;
    vector<pair<float,pair<float,float>>>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].value>>arr[i].weight;
        arr[i].per_unit=arr[i].value/arr[i].weight;
    }
    sort(arr.rbegin(),arr.rend());
    for(auto i:arr)
    {
        cout<<i.per_unit<<endl;
    }

}
