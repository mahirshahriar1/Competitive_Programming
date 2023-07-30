#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

ll power(ll a, ll b)
{
    if(b==0) return 1;
    ll res= power(a,b/2);
    if(b&1)
        return a*res*res;
    else
        return res*res;
}

int main()
{
    fastio;

    int k;
    string s;
    cin>>k;
    cin>>s;

    ll j=0,sum=0;

    for(ll i=s.size()-1;i>=0;i--)
    {
        sum+=((s[i]-'0')*power(k,j++));
    }
    cout<<sum<<endl;

    return 0;

}
