#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/*int main()
{
    ll n,a,b;

    cin>>n>>a>>b;
    ll sum=(n*(n+1))/2;

    if(a==1||b==1)
    {
        cout<<0<<endl;
        return 0;
    }

    for(ll i=1;i*a<=n;i++)
        sum-=i*a;
    for(ll i=1;i*b<=n;i++)
        sum-=i*b;

    ll lcm=(a*b)/__gcd(a,b);

    for(ll i=1;i*lcm<=n;i++)
        sum+=i*lcm;

    cout<<sum<<endl;

    return 0;
}*/

int main()
{
    ll n,a,b;

    cin>>n>>a>>b;
    ll sum=(n*(n+1))/2;


    ll lcm=(a*b)/__gcd(a,b);
    ll mA=n/a;
    ll mB=n/b;
    ll mL=n/lcm;

    cout<<sum-(a*mA*(mA+1)/2)-(b*mB*(mB+1)/2)+(lcm*mL*(mL+1)/2)<<endl;

    return 0;
}





