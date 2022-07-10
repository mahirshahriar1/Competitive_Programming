#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main ()
{
    ll t,x;

    cin>>t;

    while(t--)
    {
        cin>>x;
        if(x%2)
            cout<<x/2<<endl;
        else
            cout<<(x/2)-1<<endl;
    }

    return 0;

}

