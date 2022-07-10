#include <bits/stdc++.h>
#define ll long long int
#define mod 998244353
using namespace std;

using namespace std;

int main()
{
    ll a,b;

    cin>>a>>b;

    if(b==1)
    {
        cout<<a<<endl;
        return 0;
    }

    vector <ll> x;
    int flag=0,error=0;

    for(int i=2; i*i<=a; i++)
    {
        while(a%i==0)
        {
            x.push_back(i);
            a/=i;

            if(x.size()==b-1)
            {
                if(a!=1)
                    x.push_back(a); // a te 1 thakle x size will be b-1 so print hobena pore
                flag=1;
                break;
            }

        }
        if(flag)
            break;

    }

    if(flag&&x.size()==b)
    {
        for(auto y: x)
        {
            cout<<y<<" ";
        }
    }


    else
        cout<<"-1"<<endl;

    return 0;
}

/*#include <bits/stdc++.h>
#define ll long long int
#define mod 998244353
using namespace std;

int main()
{
    int n,k,c=0;
    vector <int> v;
    cin>>n>>k;
    int i=2;
    if(k==1)
        cout<<n<<endl;
    else
    {
        while(i*i<=n)
        {
            if(n%i==0)
            {
                cout<<n<<endl;
                n/=i;
                v.push_back(i);


                if(k==v.size()+1)
                {
                    v.push_back(n);
                    c=1;
                    break;
                }
            }
            else
            {
                ++i;
            }

        }
        cout<<n<<endl;
        if(c==1)
        {
            for(int x : v)
                cout<<x<<' ';

        }
        else
            cout<<"-1"<<endl;
    }


    return 0;
}*/

