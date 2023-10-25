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


void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> mag(n);
    takeInput(mag);
    s+="0";
    int sum(0);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1'||(s[i]=='0'&&s[i+1]=='1')){
            sum+=mag[i];
        }
        if((s[i]=='0'&&s[i+1]=='1')){
            int mn=mag[i];
            for(int j=i+1;j<n&&s[j]=='1';j++){
                mn=min(mag[j],mn);
            }
            sum-=mn;
        }
    }
    cout<<sum<<endl;

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

