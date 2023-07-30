#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    string s;
    map <string, int> m;
    while(t--)
    {
        cin>>s;
        m[s]++;
        if(m[s]>1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }



    return 0;
}
