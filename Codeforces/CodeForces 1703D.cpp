#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps = 1e-9;


void solve()
{
   int t;
   cin>>t;

   vector <string> s;
   map<string,int>m;
   for(int i=0;i<t;i++)
   {
        string temp; cin>>temp;
        s.push_back(temp);
        m[temp]++;
   }

    for(int i=0;i<t;i++)
    {
        bool found=false;
        int l=s[i].length();
        for(int j=1;j<l;j++)
        {
            string s1=s[i].substr(0,j);
            string s2=s[i].substr(j,l-j);
            if(m[s1]>0&&m[s2]>0)
            {
                found=true;
                break;
            }
        }
        cout<<(found)?1:0;

    }
    cout<<endl;

}


int main()
{
    fastio;
    int t; cin>>t;

    while(t--)
    {
        solve();
    }


    return 0;
}

