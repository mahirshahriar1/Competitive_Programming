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
    string s;
    cin>>s;    
    
    vector<int> p1(n,0),p2(n,0);
    map<int,int> m1,m2;
    p1[0]=1;
    m1[s[0]]++;
    for(int i=1;i<n;i++){
        if(m1[s[i]]==0){
            m1[s[i]]++;
            p1[i]=p1[i-1]+1;
        }else{            
            p1[i]=p1[i-1];
        }
    }
    p2[n-1]=1;
    m2[s[n-1]]++;
    for(int i=n-2;i>=0;i--){
        if(m2[s[i]]==0){
            m2[s[i]]++;
            p2[i]=p2[i+1]+1;
        }else{            
            p2[i]=p2[i+1];
        }
    }

    // print(p1)
    // print(p2)

    int ans=-1;
    for(int i=0;i<n-1;i++){
        ans=max(ans,p1[i]+p2[i+1]);
    }
    ans = max(ans, p2[n - 1] + p1[n - 2]);
    cout<<ans<<endl;  
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
