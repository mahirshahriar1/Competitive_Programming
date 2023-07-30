#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 998244353

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

vector <bool> isprime;
vector <int> primes;

void solve()
{
    int n,k;    cin>>n>>k;
    vector<int> arr(n);
    takeInput(arr);

    int cnt=0;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i-1]+arr[i+1])
            cnt++;
    }
    if(k>1){
        cout<<cnt<<endl;
    }else{
        cout<<(n-1)/2<<endl;
    }
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
