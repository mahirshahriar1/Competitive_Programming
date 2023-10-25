#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

void solve()
{

    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto& x: v)
        cin>>x;
    
    ll prefixSum[n+1]={0};
    for(int i=0;i<n;i++)
    {
        prefixSum[i+1]=v[i]+prefixSum[i];
    }
    ll minsum=prefixSum[n-1],ind=1;
    for(int i=1;i+k-1<=n;i++)
    {
        ll temp=prefixSum[i+k-1]-prefixSum[i-1];
        if(temp<minsum)
        {
            ind=i;
            minsum=temp;
        }
    }
    cout<<ind<<endl;
   
}

int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif  

    solve(); 

}                                          

/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    cin>>n>>k;
    ll sum[n+2];
    sum[0]=0;
    for(ll i=1; i<=n; i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    int index=0;
    //for(auto x:sum)  cout<<x<<" "; cout<<endl;

    for(int i=1;i<n-k+1;i++)
    {
        if((sum[i+k]-sum[i])<(sum[index+k]-sum[index]))
        {
            cout<<(sum[i+k]-sum[i])<<endl;
             index=i;
        }

    }
    cout<<index+1<<endl;

    return 0;
}*/


/*

#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,x;
    cin>>n>>x;
    vector <ll> v;
    ll sum[n];
    for(ll i=0; i<n; i++)
    {
        ll in;
        cin>>in;
        v.push_back(in);
        if(i==0)
            sum[i]=in;
        else
            sum[i]=sum[i-1]+in;
    }
    sum[-1]=0;
    ll mn=9999999999,store;

    for(ll i=x-1; i<n;i++)
    {
        if(min(sum[i]-sum[i-x],mn)<mn)
            {
                mn=sum[i]-sum[i-x];
                store=i+1-x;
            }
    }

    cout<<store+1<<endl;

    return 0;
}

*/

