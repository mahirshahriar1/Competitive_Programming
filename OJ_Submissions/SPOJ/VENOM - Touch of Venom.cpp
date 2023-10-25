#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


void solve()
{
    int h,p,a;
    cin>>h>>p>>a;
    int cnt=0,i=1;

    while(1)
    {
        h-=i*p;
        i++;
        cnt++;
        if(h<=0) break;
        h+=a;
        cnt++;

    }
    cout<<cnt<<endl;
}



int main()
{
    fastio;

    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}

