#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; ++i)
        {
         if (n % i == 0)
         {
            return false;
         }
    }
    return true;
}

int main ()
{
    string s;
    string val="0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


    while(cin>>s)
    {
        long long int length=0;
        for(int i=0;i<s.length();i++)
        {
            length+=val.find(s[i]);
        }
        //cout<<length<<endl;
        if(is_prime(length))
           cout<<"It is a prime word."<<endl;
        else
            cout<<"It is not a prime word."<<endl;
    }

    return 0;

}


