#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--)
    {
        ll a,b,x,sum=0;
        cin>>a>>b;

        deque <ll> d;
        for(int i=0;i<a;i++)
        {
            cin>>x;
            d.push_back(x);
        }
        sort(d.begin(),d.end());

        for(int i=0;i<a;i++)
        {
            if(d[i]<0&&b>0)
            {
                d[i]*=-1;
                b--;
            }
            else
                break;
        }

        sort(d.begin(),d.end());

        if(b%2==1)
            d[0]*=-1;


        for(int i=0;i<a;i++)
            sum+=d[i];

        cout<<sum<<endl;
    }

    return 0;
}
// can be done using multiset as well

/*
#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--)
    {
        ll n,k; cin>>n>>k;
        
        multiset<ll> ms;
        for(ll i=0;i<n;i++)
        {
            ll x;cin>>x;
            ms.insert(x);
        }
        for(ll i=0;i<k;i++)
        {
            ll q=(-1)**(ms.begin());
            ms.erase(ms.begin());
            ms.insert(q);
        }
        ll sum=0;
        for(auto x:ms)
            sum+=x;
        cout<<sum<<endl;
        
        
    }

    return 0;
}

/*



  
  


  
  
