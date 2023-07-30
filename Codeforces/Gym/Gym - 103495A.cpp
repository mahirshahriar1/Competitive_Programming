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

void solve(){
	int n;
	cin>>n;
	vector<int> v1,v2;
	string s;
	for(int i=0;i<n;i++){		
		cin>>s;
		v1.push_back(s[s.size()-1]-'0');
	}
	for(int i=0;i<n;i++){	
		cin>>s;
		v2.push_back(s[s.size()-1]-'0');
	}
	// print(v1)
	// print(v2)
	// level 1 2
	// oblique 3 4

	if(v1[n-1]==1 or v1[n-1]==2){		
		goto label;
	}

	for(int i=0;i<n;i++){
		if(v1[i]<=2 and v2[i]<=2){			
			goto label;
		}
		if(v1[i]>=3 and v2[i]>=3){			
			goto label;
		}
	}
	cout<<"YES"<<endl;
	return;

	label: cout<<"NO"<<endl;

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
