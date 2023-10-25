#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main()
{
    fastio;
    queue <ll> q;
    int t;cin>>t;
    while(t--)
    {
        int a; ll b;
        cin>>a;

        if(a==1)
        {
            cin>>b;
            q.push(b);
        }
        else if(a==2)
        {
            if(!q.empty())
                q.pop();
        }

        else
        {
            if(q.empty())
                cout<<"Empty!"<<endl;
            else
                cout<<q.front()<<endl;
        }
    }
    return 0;

}
