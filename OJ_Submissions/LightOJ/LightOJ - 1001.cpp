#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

//int kas=0; cout<<"Case "<<++kas<<": "<<a+b<<endl;

void solve()
{
   int a;
   cin>>a;

   if(a<=10)
        cout<<0<<' '<<a<<endl;
    else
        cout<<10<<' '<<a-10<<endl;

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





