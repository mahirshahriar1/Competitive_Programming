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
	ll m,n;
	cin>>n>>m;

	vector<ll> v(n);
	takeInput(v);

	vector<ll> presum=v;
	presum[0]=v[0];
	for(int i=1;i<n;i++){
		presum[i]+=presum[i-1];
	}
	//print(presum);

	priority_queue<ll,vector<ll>,greater<ll>> pq1;
	
	int ans(0);
	ll sum=presum[m-1];
	for(int i=m;i<n;i++){
		sum+=v[i];
		pq1.push(v[i]);
		while(sum<presum[m-1]){
			ll x=pq1.top();
			pq1.pop();
			sum-=x;
			sum+=-x;
			ans++;
		}	
	}
	//cout<<ans<<' ';
	priority_queue<ll> pq2;

	pq2.push(v[m-1]);
	for(int i=m-2;i>=0;i--){
		
		while(presum[i]<presum[m-1])
		{
			ll x=pq2.top();
			pq2.pop();
			//cout<<presum[m-1]<<' '<<presum[i]<<endl;
			presum[m-1]-=x;
			presum[m-1]+=-x;
			//cout<<presum[m-1]<<' '<<presum[i]<<endl;
			ans++;
		}		
		pq2.push(v[i]);	
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
