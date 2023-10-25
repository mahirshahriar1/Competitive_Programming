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


const int N=105;
string dp[N][N];
string str1,str2;

string solve(int i,int j){
    if(i==str1.size()) return str2.substr(j);
    if(j==str2.size()) return str1.substr(i);
    if(dp[i][j]!="*") return dp[i][j];

    string ans1=str1[i]+solve(i+1,j);
    string ans2=str2[j]+solve(i,j+1);
    
    {
        if(ans1.size()<ans2.size()) 
            dp[i][j]=ans1;
        else    dp[i][j]=ans2;
    }

    if(str1[i]==str2[j]){
        string ans3=str1[i]+solve(i+1,j+1);
        if(ans3.size()<dp[i][j].size()) dp[i][j]=ans3;
    }
    return dp[i][j];
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    while(cin>>str1>>str2){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j]="*";
            }
        }
        cout<<solve(0,0)<<endl;
    }

}
