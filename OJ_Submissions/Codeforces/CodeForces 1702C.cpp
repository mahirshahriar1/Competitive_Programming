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


void solve(){
    int n,q;
    cin>>n>>q;
    map<int,pair<int,int>> ind;

    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(ind.count(temp)==0){
            ind[temp].first=i;
            ind[temp].second=i;
        }else{
            ind[temp].second=i;
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;   
        
        if(!ind.count(a)||!ind.count(b)||ind[a].first>ind[b].second){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        
    }
   
}

int main(){
    fastio;
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
