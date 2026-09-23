#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
set<string>st;
void func(string &s,ll n,ll ind)
{
    if(ind==n)
    {
        st.insert(s);
        return;
    }
    for(ll i=ind;i<n;i++)
    {
        swap(s[ind],s[i]);
        func(s,n,ind+1);
        swap(s[ind],s[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    cin>>s;
    ll n=s.size();
    func(s,n,0);
    cout<<st.size()<<endl;
    for(auto x:st)
    {
        cout<<x<<endl;
    }
}
