#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main()
{
    fastio;
    stack <ll> s;
    int t;cin>>t;
    while(t--)
    {
        int a; ll b;
        cin>>a;

        if(a==1)
        {
            cin>>b;
            s.push(b);
        }
        else if(a==2)
        {
            if(!s.empty())
                s.pop();
        }

        else
        {
            if(s.empty())
                cout<<"Empty!"<<endl;
            else
                cout<<s.top()<<endl;
        }
    }
    return 0;

}
