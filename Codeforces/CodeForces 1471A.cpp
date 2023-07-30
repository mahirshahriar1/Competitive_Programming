#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;



void solve()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    
    takeInput(arr)

    ll sum=0,mx=0;
    for(int i=0;i<n;i++){
        mx+=ceil(arr[i]/(double)x);
        sum+=arr[i];
    }
    cout<<(ll)ceil(sum/(double)x)<<' '<<mx<<endl;   
}

int main()
{
    fastio

    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}


