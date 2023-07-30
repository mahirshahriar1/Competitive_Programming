#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    long long n;

    while(t--)
    {
        cin>>n;
        int count=0;

        int flag=1;
        if(n==1)
        {
             cout<<"0"<<endl;
             continue;
        }

        while(n>1)
        {

            if(n%2==0)
                n=n/2;
            else if(n%3==0)
                n=2*n/3;
            else if(n%5==0)
                n=4*n/5;
            else
            {
                flag=0;
                break;
            }
            count++;
            //cout<<n<<endl;

        }
        if(flag)
            cout<<count<<endl;
        else
            cout<<"-1"<<endl;

    }

    return 0;

}

