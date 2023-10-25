#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

int main()
{
    fastio;
    int n;
    cin>>n;
    map<int,int> m;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        for(int j=1; j*j<=x; j++)
        {
            if(x%j==0)
            {
                m[j]++;
                if(x/j!=j)
                    m[x/j]++;
            }

        }
    }
    int mx=1;
    for(auto x:m)
    {
        //cout<<x.first<<' '<<x.second<<endl;
        if(x.first==1)
            continue;
        mx=max(mx,x.second);
    }

    cout<<mx<<endl;


}
