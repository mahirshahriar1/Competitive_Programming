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
    int n,r,b;
    cin>>n>>r>>b;

    int partition=r/(b+1);
    int left=r%(b+1);

    vector<char> v;
    for(int i=0;i<b+1-left;i++){
        for(int j=0;j<partition;j++)
            v.push_back('R');
       v.push_back('B');
    }
    for(int i=0;i<left;i++){
        for(int j=0;j<=partition;j++)
            v.push_back('R');
       v.push_back('B');
    }    
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
    cout<<endl;
    
}


// void solve2(){
//     int n,r,b;
//     cin>>n>>r>>b;
  
//     if(b>r) swap(r,b); 
    
//     int div=r/(b+1);
//     int left=r%(b+1);
//     string ans="";
//     for(int i=0;i<b+1-left;i++){
//         string temp(div,'R');
//         ans+=temp;
//         ans+='B';
//         cout<<1<<endl;
//     }
//     for(int i=0;i<left;i++){
//         cout<<1<<endl;
//         string temp(div+1,'R');
//         ans+=temp;
//         ans+='B';
//     }
//     ans.pop_back(); 
//     cout<<ans<<endl;
   
// }

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
