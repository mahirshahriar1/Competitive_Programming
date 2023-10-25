#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    map <string,int> m;
    string s;
    while(t--)
    {
        cin>>s;
        auto itr=m.find(s);
        if(itr!=m.end())
        {
            cout<<s<<""<<m[s]<<endl;
            m[s]++;
        }
        else
        {
            cout<<"OK"<<endl;
            m[s]++;
        }
    }

    return 0;
}
