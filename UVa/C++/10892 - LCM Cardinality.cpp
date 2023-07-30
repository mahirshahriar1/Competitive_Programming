#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return (a/__gcd(a,b))*b;
}

int main()
{
    fastio;
    int n;

    while(cin>>n, n!=0)
    {
        if(n==1)
        {
            cout<<1<<' '<<1<<endl;
            continue;
        }
        vector <int> divs;

        for(int i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                divs.push_back(i);
                if(n/i!=i)
                    divs.push_back(n/i);
            }
        }

        int cnt=0;

        for(int i=0; i<divs.size(); i++)
        {
            for(int j=i+1; j<divs.size(); j++)
            {
                if(lcm(divs[i],divs[j])==n)
                {
                   // cout<<divs[i]<<' '<<divs[j]<<endl;
                    cnt++;
                }
            }
        }
        cout<<n<<' '<<cnt+1<<endl;


    }


}
