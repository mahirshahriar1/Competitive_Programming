#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    fastio;
    ll n,t,c;
    cin>>n>>t>>c;

    ll res=0,cnt=0 ,temp;
    while(n--)
    {
        cin>>temp;
        if(temp>t)
            cnt=0;
        else
            cnt++;

        if(cnt>=c)
            res++;
    }
    cout<<res<<endl;


    return 0;
}
