#include<bits/stdc++.h>
using namespace std;

bool is_prime(long long int n)
{
    for (int i = 2; i * 1LL * i <= n; ++i)
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
    long long int x;

    cin>>x;

    if(x<5)
        cout<<"-1"<<endl;
    else if(is_prime(x-2))
        cout<<"2 "<<x-2<<endl;
    else
        cout<<"-1"<<endl;


    return 0;

}

