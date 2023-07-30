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
    char c;
    cin>>n>>c;
    string s;
    cin>>s;

    vector<int> ind;
    for(int i=0;i<n;i++){
        if(s[i]=='g'){
            ind.push_back(i);
        }
    }
    int size=ind.size();
    for(int i=0;i<size;i++){
        ind.push_back(ind[i]+n);        
    }
    int ans=-INT_MAX;
    for(int i=0;i<n;i++){
        if(s[i]==c){
            auto itr=lower_bound(range(ind),i);
            ans=max(ans,*itr-i);
        }
    }
    cout<<ans<<endl;   

}

int main()
{
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

