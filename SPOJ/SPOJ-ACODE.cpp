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

const int N=5000+5;
int dp[N];
string s;
int solve(int i){
    if(i==s.size()) return 1;
    if(dp[i]!=-1) return dp[i];

    int dig1=s[i]-'0';
    int val=0;
    if(dig1!=0){        
        val=solve(i+1);
        if(i+1<s.size()){           
            int num=dig1*10+s[i+1]-'0';
            if(num<=26){
                val+=solve(i+2);
            }
        }
    }
    
    return dp[i]=val;
}

int main(){
    fastio  

    while(cin>>s,s!="0"){
        memset(dp,-1,sizeof dp);
        cout<<solve(0)<<'\n';
    }
}

/* 
2 5 1 1 4
25 1 1 4
25 11 4
25 1 14
2 5 11 4
2 5 1 14
 */
