#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t1,t2; cin>>t1>>t2;

    map <string,ll>m;
    while(t1--)
    {
        ll x;
        string s;
        cin>>s>>x;
        m[s]=x;
    }

   for(int i=0;i<t2;i++)
   {
       ll sum=0;
       string ss;
       while(1)
       {
           cin>>ss;
           if(ss==".")
            break;

            if(m.find(ss)!=m.end())
                sum+=m[ss];
       }
    cout<<sum<<endl;
   }



    return 0;
}
