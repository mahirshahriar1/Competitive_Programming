#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)
#define mod 1000000007
const double eps=1e-9;

ll factorial[21];

void precompute()
{
    factorial[0]=1;
    for(int i=1;i<=20;i++)
        factorial[i]=i*factorial[i-1];    
}


int kas=0;

void solve()
{
    ll n;
    cin>>n;
    vector<int> ans;

    for(int i=20;i>=0;i--)
    {
        if(factorial[i]<=n)
        {
            n-=factorial[i];
            ans.push_back(i);
        }
    }

    cout<<"Case "<<++kas<<": ";
    if(n==0)
    {
       for(int i=ans.size()-1; i>0; i--)
            cout<<ans[i]<<"!+";
        
        cout<<ans[0]<<"!"<<endl;
        return;
    }
  
    cout<<"impossible"<<endl;   

}

int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif
    precompute();

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
