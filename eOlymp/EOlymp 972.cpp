https://www.eolymp.com/en/problems/972

#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


int main()
{
   ios_base::sync_with_stdio(false);  cin.tie(nullptr);

   ll n;
  cin>>n;
  vector <pair<ll,pair<ll, ll>>> v(n);


   for(int i=0;i<n;i++)
   {
       cin>> v[i].first;
       cin>>v[i].second.first;
       cin>>v[i].second.second;
   }
   sort(v.begin(), v.end());
   for(auto x: v)
   {
        cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
   }


    return 0;
}


