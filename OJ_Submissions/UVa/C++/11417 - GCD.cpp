#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


int GCD(int a, int b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);



    ll x;
    while(cin>>x, x!=0)
    {
        ll G=0;
        for(ll i=1; i<x; i++)
            for(ll j=i+1; j<=x; j++)
            {
                G+=GCD(i,j);
            }
        cout<<G<<endl;

    }


}



