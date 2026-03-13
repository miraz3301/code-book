#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
ll cnt;
void fun(string &ans,string s,unordered_map<char,bool>&mp,ll k)
{
    if(cnt==k)return;
    if(ans.size()==s.size())
    {
        cout<<ans<<endl;
        cnt++;
        return;
    }
    for(char c:s)
    {
        if(cnt==k)return;
        if(!mp[c])
        {
            ans+=c;
            mp[c]=true;
            fun(ans,s,mp,k);
            mp[c]=false;
            ans.pop_back();
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
   
        ll n,k;
        cin>>n>>k;
        string s;
        for(ll i=0;i<n;i++)s+=('A'+i);
        unordered_map<char,bool>mp;
        string ans;
        cnt=0;
        fun(ans,s,mp,k);
    
}
