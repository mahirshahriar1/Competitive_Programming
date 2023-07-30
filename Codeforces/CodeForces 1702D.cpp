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
#define rev(v) v.rbegin(),v.rend()
typedef long long int ll;
const double eps=1e-9;

void solve(){
      string s;
      cin>>s;
      int p;
      cin>>p;
      int n=s.size();

      ll cost=0;
      for(auto x:s) cost+=x-'a'+1;
      
      string tmp=s;
      sort(rev(tmp));
      
      map<char,int>mp;
      for(int i=0;i<n;i++){
        if(cost>p){          
          mp[tmp[i]]++;
          cost-=tmp[i]-'a'+1;
        }
      }
       for(int i=0;i<n;i++){
        if(mp[s[i]]){
          mp[s[i]]--;
          continue;
        }
        cout<<s[i];
      }
      cout<<endl;
      
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
