//https://codeforces.com/gym/390737/problem/B

#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
 
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
 
   ll t;
   cin>>t;
   while(t--)
   {
       ll x;
       cin>>x;
       ll ans=0;
       for(int i=0;i<x;i++)
       {
           ll in;
           cin>>in;
            ans=(ans|in);
       }
       cout<<ans<<endl;
 
   }
 
 
   return 0;
}
