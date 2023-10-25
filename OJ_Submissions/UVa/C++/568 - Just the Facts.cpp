#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector <ll> ans;
void sieve()
{
    ans.push_back(1);
    ll res=1;
    for(int i=1;i<=10000;i++)
    {
        res*=i;
        while(res%10==0)
        {
             res/=10;
        }
        res=res%100000;
        ans.push_back(res%10);
    }

}

int main()
{

    fastio;
    sieve();

    int in;
    while(cin>>in)
    {
        printf("%5d -> %d\n",in, ans[in]);
    }

}

