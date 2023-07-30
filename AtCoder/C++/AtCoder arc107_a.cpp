#include <bits/stdc++.h>
#define ll long long int
#define mod 998244353

using namespace std;

int main()
{
    ll a,b,c,ans1,ans2,ans3;

    cin>>a>>b>>c;


    ans1=(((a%mod)*((a+1)%mod))/2)%mod;
    ans2=(((b%mod)*((b+1)%mod))/2)%mod;
    ans3=(((c%mod)*((c+1)%mod))/2)%mod;


    cout<<((((ans1%mod)*(ans2%mod))%mod)*(ans3%mod))%mod<<endl;


    return 0;
}
