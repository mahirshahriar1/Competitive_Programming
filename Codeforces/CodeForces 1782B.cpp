#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;


void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	takeInput(v)

	int ans=0;
	sort(range(v));

	if(v.front()>0) ans++;
	for(int i=0;i<n;i++){
		if(v[i]<=i and (i+1==n or v[i+1]>i+1)){
			ans++;
		}
	}
	cout<<ans<<endl;

}

int main(){
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
