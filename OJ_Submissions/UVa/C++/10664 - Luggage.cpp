#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;


vector<int> v;

int dp[210][100];

int solve(int i,int sum){
    if(i==v.size()){
        return (sum==0?1:0);
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int ans=0;
    ans+=solve(i+1,sum);
    ans+=solve(i+1,sum-v[i]);
    return dp[i][sum]=ans;
}

void solve(){
    v.clear();
    string s;
    getline(cin,s);   
    stringstream ss(s);
    int x;
    int sum=0;
    while(ss>>x){
        v.push_back(x);
        sum+=x;
    }  
    if(sum%2){
        cout<<"NO"<<endl;
        return;
    }
    sum/=2;
    memset(dp,-1,sizeof(dp));   
    cout<<(solve(0,sum)>1?"YES":"NO")<<endl;
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
       solve();
    }

    return 0;
}
