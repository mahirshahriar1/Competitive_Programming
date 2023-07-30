#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

const ll eps=10e-9;
vector <double> logs;

void sieve()
{
    logs.push_back(0);
    for(int i=1;i<=1e6;i++)
        logs.push_back(logs[i-1]+log10(i));
}

int main()
{

    fastio;
    int t,kase=0;
    cin>>t;

    sieve();

    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll ans=(logs[a]/log10(b))+1+eps;
        cout<<"Case "<<++kase<<": "<<ans<<endl;
    }

}
