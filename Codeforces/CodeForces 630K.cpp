#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    ll n;
    cin>>n;
    cout<<n-n/2-n/3-n/5-n/7+n/(2*3)+n/(2*5)+n/(2*7)+n/(3*5)+n/(3*7)+n/(5*7)-n/(2*3*5)-n/(2*3*7)-n/(2*5*7)-n/(3*5*7)+n/(2*3*5*7)<<endl;

    return 0;
}
