#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);  cin.tie(nullptr);

    ll n,d;
    cin>>n>>d;

    while(d--)
    {
        if((n%10)!=0)
        {
            n-=1;
        }
        else
        {
            n/=10;
        }
    }
    cout<<n<<endl;


    return 0;
}

