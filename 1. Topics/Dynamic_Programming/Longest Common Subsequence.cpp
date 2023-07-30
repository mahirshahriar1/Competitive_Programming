#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);


#define MAX_LEN 1100
#define EMPTY_VALUE -1

int dp[105][105];

int lcs(vector<int> s1, vector<int> s2, int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}





int mem[MAX_LEN][MAX_LEN];


int lcs(int i,int j, string &S, string &W) {
    if(i == S.size() || j == W.size()) return 0;
    
    if(mem[i][j] != EMPTY_VALUE) {
        return mem[i][j];
    }        
    
    int ans=0;
    if(S[i] == W[j]) {
        ans = 1 + lcs(i + 1,j + 1, S, W);
    }
    else{
        int val1 = lcs(i + 1, j, S, W);
        int val2 = lcs(i,j + 1, S, W);
        
        ans=max(val1,val2);
    }
    
    mem[i][j] = ans;
    return mem[i][j];
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    
    string a,b;
    while(getline(cin,a) and getline(cin,b)){
        memset(mem,-1,sizeof(mem));
        cout<<lcs(0,0,a,b)<<endl;
    }
    


}
