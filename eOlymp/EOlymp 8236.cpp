#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


ll mod(ll a)
{
    return ((a%2)+2)%2;
}

bool comp(ll a, ll b)
{

    if(mod(a)&&mod(b))
    {
        return a<b;
    }

    else if(!mod(a)&&!mod(b))
    {
        return a>b;
    }

    return mod(a)>mod(b);

}


int main()
{
   ios_base::sync_with_stdio(false);  cin.tie(nullptr);

   int x;
    cin>>x;

   vector <ll> v;

   for(int i=0; i<x;i++)
   {
        ll n;
        cin>> n;
        v.push_back(n);
   }

   sort(v.begin(), v.end(), comp);

   for(auto x:v)
    cout<<x<<" ";
   cout<<endl;


    return 0;
}

