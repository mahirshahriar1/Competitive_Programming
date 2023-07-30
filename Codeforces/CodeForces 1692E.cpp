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

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);

    ll sum=0;
    for(auto& x:v){
        cin>>x;
        sum+=x;
    }
    if(sum<k){
        cout<<-1<<endl;
    }else if(sum==k){
        cout<<0<<endl;
    }else{
        sum=0;
        int l=0,res=-1;
        for (int r = 0; r < n; ++r){
            sum += v[r];
            while (sum > k){
                sum -= v[l];
                l++;
            }
            if (sum == k)
                res = max(res, r - l + 1);
        }
        cout<<n-res<<endl;
    }

}

int main()
{
    fastio;
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
    

}                                          
