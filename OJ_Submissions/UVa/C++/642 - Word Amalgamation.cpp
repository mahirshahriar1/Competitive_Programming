#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

bool comp(string one, string two)
{
    sort(one.begin(),one.end());
    sort(two.begin(), two.end());

    if(one==two)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string x;
    set <string> s;
    vector <string> v;
    while(cin>>x, x!="XXXXXX")
        s.insert(x);

    while(cin>>x, x!="XXXXXX")
        v.push_back(x);

    for(int i=0;i<v.size();i++)
    {
        int flag=0;
        for(auto x: s)
        {
            if(comp(x,v[i]))
            {
                 cout<<x<<endl;
                 flag=1;
            }

        }
        if(!flag)
            cout<<"NOT A VALID WORD"<<endl;
        cout<<"******"<<endl;
    }



    return 0;
}

