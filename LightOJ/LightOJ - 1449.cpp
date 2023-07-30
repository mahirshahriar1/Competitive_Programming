#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main()
{
    fastio;
    int kas=0;
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       if(s[4]!='s')
        cout<<"Case "<<++kas<<": "<<s.substr(0,4)<<'s'<<s.substr(4,s.length()-4)<<endl;
       else
        cout<<"Case "<<++kas<<": "<<s<<endl;
    }



    return 0;

}

