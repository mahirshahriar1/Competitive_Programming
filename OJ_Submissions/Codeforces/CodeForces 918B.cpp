#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t1,t2; cin>>t1>>t2;
    string s1,s2;

    map <string, string> m;
    while(t1--)
    {
        cin>>s1>>s2;
        m[s2]=s1;
    }

    while(t2--)
    {
        cin>>s1>>s2;
        auto itr=m.find(s2.substr(0,s2.length()-1));
        if(itr!=m.end())
            cout<<s1<<" "<<itr->first<<"; #"<<itr->second<<endl;
    }


    return 0;
}
