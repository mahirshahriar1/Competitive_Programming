#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
typedef long long int ll;

int main()
{
    fastio
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin>>s;
    
    ll cnt=0;
    while(s.size()!=1){ 
        ll sum=0;    
        for (ll i=0;i<s.size();i++)
            sum+=(s[i]-'0');    
        cnt++;
        s=to_string(sum);
    }

    cout<<cnt<<endl;   

    return 0;
}
