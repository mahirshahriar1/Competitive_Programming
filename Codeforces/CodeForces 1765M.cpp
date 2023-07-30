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

int GCD(int a, int b){
    if(b==0) return a;
    return GCD(b,a%b);
}

int lcm(int a, int b){
    return (a/GCD(a,b))*b;
}


int a,b,n;
bool isValid(int x){
	if(lcm(x,n-x)<lcm(a,b)){
		return true;
	}
	return false;
}

void solve(){
	cin>>n;

	a=1,b=n-1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			if(isValid(i)){
				a=i;
				b=n-i;
			}
			if(isValid(n/i)){
				a=n/i;
				b=n-(n/i);
			}
		}
	}
	cout<<a<<' '<<b<<endl;


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
