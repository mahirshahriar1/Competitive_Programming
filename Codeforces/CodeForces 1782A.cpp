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
	int w,d,h;
	cin>>w>>d>>h;
	int a,b,f,g;
	cin>>a>>b>>f>>g;

	int x=min({a,b,f,g,w-a,w-f, d-b,d-g});
	int ans=h+2*x+abs(g-b)+abs(f-a);
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
