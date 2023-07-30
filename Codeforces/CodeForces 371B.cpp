#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    cin>>a>>b;

    int a1[3],b1[3];
    a1[0]=a1[1]=a1[2]=0;
    b1[0]=b1[1]=b1[2]=0;

    while(!(a%2))
    {
        a1[0]++;
        a/=2;
    }
     while(!(a%3))
    {
        a1[1]++;
        a/=3;
    }

     while(!(a%5))
    {
        a1[2]++;
        a/=5;
    }

     while(!(b%2))
    {
        b1[0]++;
        b/=2;
    }
    while(!(b%3))
    {
        b1[1]++;
        b/=3;
    }

     while(!(b%5))
    {
        b1[2]++;
        b/=5;
    }

    if(a!=b)
        cout<<"-1"<<endl;
    else
        cout<<abs(a1[0]-b1[0])+abs(a1[1]-b1[1])+abs(a1[2]-b1[2])<<endl;


    return 0;
}
