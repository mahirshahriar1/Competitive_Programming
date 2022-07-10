#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    long long x;

    while(t--)
    {
        long long sum=0;
        cin>>x;
        if(x==1)
        {
            cout<<"0"<<endl;
             continue;
        }

        for(int i=1;i*1LL*i<=x;i++)
        {
            if(x%i==0&&i!=x)
            {
                    sum+=i;
                  if(x/i!=i&&x/i!=x)
                    sum+=x/i;
            }

        }
        cout<<sum<<endl;

    }

    return 0;

}

