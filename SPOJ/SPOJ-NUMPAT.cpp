#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


const int N=10;
ll dp[N][N];
int n,m;


ll solve(int x,int y){
    if(x==n and y==m) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    ll ways=0;
    if(x+1<=n)
        ways+=solve(x+1,y);
    if(y+1<=m)
        ways+=solve(x,y+1);

    return dp[x][y]=ways;
} // prob is that we have to use memset everytime



ll solve2(int x,int y){
    if(x==1 and y==1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    ll ways=0;
    if(x-1>=1)
        ways+=solve(x-1,y);
    if(y-1>=1)
        ways+=solve(x,y-1);

    return dp[x][y]=ways;
} //bottom up

int main(){

    int t;
    cin>>t;

    memset(dp,-1,sizeof(dp));

    while(t--){
        //memset(dp,-1,sizeof(dp));
        cin>>n>>m;
        cout<<solve2(n,m)<<endl;
    }



    return 0;
}
