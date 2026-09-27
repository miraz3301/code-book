#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
ll n,cnt;
vector<string>board;
vector<bool>col,diag1,diag2;
void solve(ll row)
{
    if(row==n)
    {
        cnt++;
        return;
    }
    for(ll c=0;c<n;c++)
    {
        if(board[row][c]=='*')continue;
        if(col[c] or diag1[row-c+n] or diag2[row+c])continue;
        col[c]=true;
        diag1[row-c+n]=true;
        diag2[row+c]=true;
        solve(row+1);
        col[c]=false;
        diag1[row-c+n]=false;
        diag2[row+c]=false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll tc=1;
    while(1)
    {
        cin>>n;
        if(!n)break;
        board.resize(n);
        for(ll i=0;i<n;i++)cin>>board[i];
        cnt=0;
        col.assign(n,false);
        diag1.assign(2*n,false);
        diag2.assign(2*n,false);
        solve(0);
        cout<<"Case "<<tc++<<": "<<cnt<<endl;
    }
}
