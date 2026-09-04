#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string txt,pat;
    cin>>txt>>pat;

    vector<ll>pi(pat.size(),0);
    for(ll i=1;i<pat.size();i++)
    {
        ll j=pi[i-1];
        while(j>0 and pat[i]!=pat[j])j=pi[j-1];
        if(pat[i]==pat[j])j++;
        pi[i]=j;
    }
    ll i=0,j=0;
    vector<ll>v;
    while(i<txt.size())
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
            if(j==pat.size())
            {
                v.push_back(i-pat.size());
                j=pi[j-1];
            }
        }
        else
        {
            if(!j)i++;
            else j=pi[j-1];
        }
    }
    cout<<v.size();
}
