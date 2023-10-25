#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main ()
{
    int a,b,c=0;
    cin>>a>>b;
    while(a<=b)
    {
        a=a*3;
        b=b*2;
        c++;
    }
    cout<<c<<endl;

    return 0;

}

