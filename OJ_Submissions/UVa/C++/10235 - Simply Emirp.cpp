#include<bits/stdc++.h>
using namespace std;

bool is_prime(long long int n) {
    for (int i = 2; i * 1LL * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long long int rev(long long int y)
{
    long long int reversed_number=0;
    while(y)
    {
        reversed_number=reversed_number*10+y%10;
        y/=10;

    }
    return reversed_number;
}

bool is_emirp(long long int n)
{
    if(is_prime(n))
    {
        long long int x=rev(n);
        if(is_prime(x))
            return true;
        else
            return false;
    }
    else
        return false;
}


int main ()
{

    long long int x;

    while(cin>>x)
    {
        if(is_emirp(x)&&rev(x)!=x)
            cout<<x<<" is emirp."<<endl;
        else if(is_prime(x))
            cout<<x<<" is prime."<<endl;
        else
            cout<<x<<" is not prime."<<endl;
    }

    return 0;

}

