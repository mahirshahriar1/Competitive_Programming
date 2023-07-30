//https://codeforces.com/gym/390737/problem/A

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
      string s;
      cin>>s;
      map<char,ll>m;
      for(int i=0;i<s.size();i++)
      {
            m[s[i]]++;
      }
      if(m['a']==m['b'])
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;

    }

   return 0;
}


