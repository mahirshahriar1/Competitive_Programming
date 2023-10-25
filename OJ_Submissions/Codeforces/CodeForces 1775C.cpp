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
	vector<int> v[n];

	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		while(x--){
			int val;
			cin>>val;
			v[i].push_back(val);
			mp[val]++;
		}
	}
	bool ok=false;
	for(int i=0;i<n;i++)
	{
		bool flag=true;
		for(int j=0;j<v[i].size();j++)
		{
			//cout<<v[i][j]<<" ";
			if(mp[v[i][j]]==1)
			{
				flag=false;
				break;
			}
		}
		if(flag){
			ok=true;
			break;
		}
	}
	if(!ok){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}

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
