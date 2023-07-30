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
    vector<int> v(n);
    takeInput(v)
    vector<int> ans(n);
    ans[0]=v[0];
    bool flag=false;
    for(int i=1;i<n;i++){
        if(ans[i-1]-v[i]>=0&&ans[i-1]+v[i]>=0&&v[i]!=0){
            //cout<<v[i]<<' '<<endl;      
            flag=true;
            break;
        }
        ans[i]=v[i]+ans[i-1];        
    }
    if(flag){
        cout<<-1<<endl;
    }else{
        print(ans);
    }

}


int main()
{
	fastio
#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

   int t;
   cin>>t;
   while(t--)
   {
      solve();
   }  
	
	return 0;
}
