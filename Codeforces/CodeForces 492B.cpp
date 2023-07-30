#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-10;


void solve(){
   int n,l;
   cin>>n>>l;

   vector<int> v(n);
   takeInput(v);
   sort(range(v));

   double diff=-INT_MAX;
   for(int i=1;i<n;i++){
    diff=max(diff,(v[i]-v[i-1])/2.0);
   }
   diff=max(diff,(v[0]-0.0));
   diff=max(diff,((double)l-v[n-1]));
   cout<<precision(10)<<(diff+eps)<<endl;
}

int main()
{
    fastio
    #ifndef ONLINE_JUDGE
           freopen("input.txt", "r", stdin);
           freopen("output.txt", "w",stdout);
    #endif

    solve(); 

}

