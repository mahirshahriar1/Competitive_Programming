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

string a,b;
vector<string> words1,words2;

int dp[1005][1005];
int lcs(int i,int j) {
    if(i == words1.size() || j == words2.size()) return 0;
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }        
    
    int ans=0;
    if(words1[i] == words2[j]) {
        ans = 1 + lcs(i + 1,j + 1);
    }
    else{
        int val1 = lcs(i + 1, j);
        int val2 = lcs(i,j + 1);        
        ans=max(val1,val2);
    }
    
    dp[i][j] = ans;
    return dp[i][j];
}

vector<string> words(string s){
    vector<string> ret;

    string tmp;
    
    for(auto c: s){
        if(isalnum(c)){
            tmp+=c;
        }else if(!tmp.empty()){
            ret.push_back(tmp);
            tmp.clear();
        }
    }

    if(!tmp.empty()) ret.push_back(tmp);
    return ret;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int kas=0;
    
    while(getline(cin,a) and getline(cin,b)){
        memset(dp,-1,sizeof(dp));
        
        words1=words(a);
        words2=words(b);
        if(!words1.size() or !words2.size()){
            cout<<setw(2)<<++kas<<". Blank!"<<endl;
            continue;
        }     
        
        //print(words1) print(words2)
        cout<<setw(2)<<++kas<<". Length of longest match: "<<lcs(0,0)<<endl;
        
    }

    return 0;

}
