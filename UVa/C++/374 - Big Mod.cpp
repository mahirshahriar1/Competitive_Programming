#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


ll power(ll b, ll e, ll m)
{
    if(e==0)
        return 1;
    ll result=power(b,e/2,m);
    result=(result*result)%m;
    if(e%2)
        result=(result*b)%m;

    return result;
}


int main()
{
    fastio;
   ll b,e,m;

   while(cin>>b>>e>>m)
   {
       cout<<power(b,e,m)<<endl;
   }
}
