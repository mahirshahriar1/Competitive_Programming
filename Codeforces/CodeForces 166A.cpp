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

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first>b.first;
}

void solve(){
	int k,n;
	cin>>n>>k;
	vector<pair<int,int>> v;	
	map<pair<int,int>, int> mp;	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		//cout<<a<<' '<<b<<endl;
		v.push_back({a,b});
		mp[{a,b}]++;
	}
	sort(range(v),comp);
	//int i=1;	for(auto x:v) cout<<i++<<'-'<<x.first<<' '<<x.second<<endl;
	//cout<<v[k-1].first<<endl;
	cout<<mp[v[k-1]]<<endl;

	v.clear();
	mp.clear();
}

int main(){
	fastio  
	#ifndef ONLINE_JUDGE  
		   freopen("input.txt", "r", stdin); 
		   freopen("output.txt", "w",stdout);
	#endif

	solve();

	return 0;
}
