#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,m,x,t,d;

    cin>>n>>m>>x>>t>>d;

    if(m>=x)
        cout<<t<<endl;
    else
    {
        int a=t-(x*d);
        cout<<m*d+a<<endl;
    }


    return 0;

}
