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

void solve()
{
	int n,k,even=0,odd=0;
	cin>>n>>k;
	vector<int> v(n);
	for(auto &x:v){
		cin>>x;
		if(x%2) odd++;
		else even++;
	}

	if(!odd){
		cout<<"No"<<endl;
		return;
	}
	if(k%2==0&&even==0){
		cout<<"No"<<endl;
		return;
	}
	k--;
	odd--;
	while(k>=2 && odd>=2){
		k-=2;
		odd-=2;
	}
	while(k && even){
		k--, even--;
	}
	if(k){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	
}

int main()
{
	fastio
#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int test;
	cin >> test;
	while (test--){
		solve();
	}

	return 0;
}
