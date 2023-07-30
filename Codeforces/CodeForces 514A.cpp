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


int main(){
	#ifndef ONLINE_JUDGE  
		   freopen("input.txt", "r", stdin); 
		   freopen("output.txt", "w",stdout);
	#endif
	
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.size();i++){
        v.push_back(s[i]-'0');
    }

    for(int i=0;i<s.size();i++){
        int change=9-v[i];
        if(i==0){
            if(change<v[i]&&change>0)
                 v[i]=change;
            continue;
        }
        if(change<v[i])
            v[i]=change;
    }
    for(auto x: v)
        cout<<x;
    cout<<endl;
    

	
}
