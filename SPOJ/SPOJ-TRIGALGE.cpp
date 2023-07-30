#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
 
const double eps=1e-9;
 
double a,b,c;
 
double eqn(double x)
{
    return (a*x+b*sin(x));
}
 
double binarysearch(double key)
{
    double l=0, r=key;
 
    while(l+eps<r){
        double mid = (l + r) / 2;
        if (eqn(mid)> key+eps){
            r=mid;
        }else if(eqn(mid)+eps<key){
            l=mid;
        }else{
            return mid;
        }
    }
 
 
}
 
 
int main()
{
    fastio;
 
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        printf("%lf\n", binarysearch(c));
       }
 
 
    return 0;
}
