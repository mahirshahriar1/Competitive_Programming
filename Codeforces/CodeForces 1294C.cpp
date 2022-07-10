#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long n,a,b,c,rem;
        cin>>n;

        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                a=i;
                break;
            }
        }
        rem=n/a;
        for(int j=a+1;j*j<=rem;j++)
        {
            if(rem%j==0)
            {
                b=j;
                c=rem/b;
                if(c<=b)
                    c=0;
                break;
            }
        }
        if(a*b*c==n)
            cout<<"YES\n"<<a<<" "<<b<<" "<<c<<endl;
        else
            cout<<"NO"<<endl;



    }

    return 0;
}
