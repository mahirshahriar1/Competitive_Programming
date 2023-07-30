#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const double eps=1e-9;

double eqn(double x)
{
    return ((x*x)+x);
}
bool test_equal(double x, double y) {
    return abs(x - y) < eps;
}

ll binarysearch(ll key)
{
    ll l=0, r=1e9, res;
    while(l<=r){
        ll mid = (l + r) / 2;
        ll ans=(mid*(mid+1))/2;
        if (ans <= key)
        {
            res=mid;
            l=mid+1;
        }
        else
            r=mid-1;

    }
    return res;
}


int main()
{
    fastio;

    ll t,input;
    cin>>t;
    while(t--)
    {
        cin>>input;
       cout<<binarysearch(input)<<endl;

    }

    return 0;
}
