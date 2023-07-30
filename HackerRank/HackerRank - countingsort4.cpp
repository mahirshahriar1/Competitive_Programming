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

bool comp(pair<int,pair<int,string>> a,pair<int,pair<int,string>> b){
    if(a.second.first==b.second.first){
        return a.first<b.first;
    }
    return a.second.first<b.second.first;
}

int main()
{    

   
   int n;
   cin>>n;
   vector<pair<int,pair<int,string>>> v(n);

   for(int i=1;i<=n;i++){
        int in; cin>>in;
        string s; cin>>s;
        v[i-1]={i,{in,s}};    
   }

   sort(v.begin(),v.end(),comp);
   
   for(auto x: v){
    if(x.first>n/2){
        cout<<x.second.second<<' ';
    }else{
        cout<<"-"<<' ';
    }
   }

}
