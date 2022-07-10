#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll module(string num, ll mod)
{
    ll i=0;
    if(num[0]=='-')
        i=1;

    ll res=0;
    for( ;i<num.size();i++)
    {
        ll d=num[i]-'0';
        res=(res*10)+d;
        res%=mod;
    }
    if(num[0]=='-')
        return -res;
    else
        return res;
}

int main ()
{

    int t,c=1,x;
    cin>>t;
    string s1;
    while(t--)
    {
        cin>>s1;
        cin>>x;
        ll ans=(module(s1,x)+x)%x;
        if(!ans)
            cout<<"Case "<<c++<<": divisible"<<endl;
        else
           cout<<"Case "<<c++<<": not divisible"<<endl;

    }


    return 0;

}

