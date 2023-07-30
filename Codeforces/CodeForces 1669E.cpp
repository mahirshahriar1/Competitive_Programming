#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

void solve()
{
	int n;
	cin>>n;
	vector<string> v(n);
	map<string,int> str_occ;
	map<char,int> fc_occ;
	map<char,int> sc_occ;	
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		fc_occ[v[i][0]]++;
		sc_occ[v[i][1]]++;
		str_occ[v[i]]++;
	}

	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(ll)max(0, fc_occ[v[i][0]]-str_occ[v[i]]);
		ans+=(ll)max(0, sc_occ[v[i][1]]-str_occ[v[i]]);
		fc_occ[v[i][0]]--;
		sc_occ[v[i][1]]--;
		str_occ[v[i]]--;
	}
	cout<<ans<<endl;

}

int main(){
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
