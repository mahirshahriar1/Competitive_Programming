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

	int n,c1,c2;
	cin>>n>>c1>>c2;
	vector<string> v(n);

	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		int x=min(3*c1,3*c2);

		bool flag=false;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(v[i][j]==v[i][k]  and j!=k){
					flag=true;
					break;
				}
			}
		}
		
		if(flag){
			int y=c1+c2; //3
			int z=2*c2;  //4~3
			//int p=3*c1 //3 ~not necessary (line 32)
			x=min(x,min(y,z));
		}
		//cout<<v[i]<<' '<<x<<endl;
		sum+=x;
	}
	cout<<sum<<endl;

}
