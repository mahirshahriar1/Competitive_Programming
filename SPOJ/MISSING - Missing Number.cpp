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
const double eps=1e-9;

int main(){
	fastio  
	#ifndef ONLINE_JUDGE  
		   freopen("input.txt", "r", stdin); 
		   freopen("output.txt", "w",stdout);
	#endif
	ll n,k;
	cin>>n>>k;
	vector<ll> v;

	for(ll i=0;i<n-1;i++){
		ll x;
		cin>>x;
		v.push_back(x);
	}
	sort(range(v));
	//print(v)

	if(v[n-2]!=n+k-1){
		//cout<<v[n-1]<<endl;
		cout<<n+k-1<<endl;
		return 0;
	}

	ll y=k;
	for(ll i=0;i<n-1;i++){
		if(v[i]!=y){
			//cout<<v[i]<<endl;
			cout<<y<<endl;
			return 0;
		}
		y++;
	}

}
