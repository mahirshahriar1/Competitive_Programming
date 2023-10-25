#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


ll power(ll a, ll b,ll m)
{
    if(b==0) return 1;
    ll res= power(a,b/2,m);
    if(b&1)
        return a%m*res%m*res%m;
    else
        return res%m*res%m;
}

int main()
{
    fastio;
   ll t;

   cin>>t;
   while(t--)
   {
       ll a,b;
       cin>>a>>b;
       cout<<power(a,b,10)<<endl;
   }
}
