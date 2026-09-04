#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s,p;
    cin>>s>>p;
    vector<ll>lps(p.size(),0);
    ll pre=0;
    ll ind=1;
    while(ind<p.size())
    {
        if(p[ind]==p[pre])
        {
            pre++;
            lps[ind]=pre;
            ind++;
        }
        else
        {
            if(!pre)
            {
                lps[ind]=0;
                ind++;
            }
            else pre=lps[pre-1];
        }
    }
    ll i=0,j=0;
    vector<ll>v;
    while(i<s.size())
    {
        if(s[i]==p[j])
        {
            i++;
            j++;
            if(j==p.size())
            {
                v.push_back(i-p.size());
                j=lps[j-1];
            }
        }
        else
        {
            if(!j)i++;
            else j=lps[j-1];
        }
    }
    cout<<v.size();
}
