#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   ll n;
   cin>>n;

   map<string,ll>m;

   for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(m[s]==0)
            cout<<s<<endl;
        else
            cout<<s<<"("<<m[s]<<")"<<endl;
        m[s]++;

    }


   return 0;
}


