#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    fastio;
    int t;
    cin>>t;

    while(t--)
    {
        ll g,l;
        cin>>g>>l;
        ll a=g;
 // g is gcd of a and b. the minimum value that can be divided by g is g itself. so a=g. (a<=b)

        if(l%g)
            cout<<"-1"<<endl;
// if g cannot divide lcm then impossible. Greatest common divisor SHOULD BE ABLE TO DIVIDE the least common multiple.
        else
        {
            // lcm(a,b)=a*b/ gcd(a,b);
            ll b= (g/a)*l; // g and a are same so b is basically equal to l.. ll b=l;
            cout<<a<<" "<<b<<endl;
        }

    }

}
