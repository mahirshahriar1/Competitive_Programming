#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=1e5+10;
int dp[N];


//Top down approach
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];

    return dp[n]=fib(n-1)+fib(n-2);
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    memset(dp,-1,sizeof(dp));
    int n;
    while(cin>>n){
        cout<<fib(n)<<endl;
    }

    //bottom down is iterative approach
    return 0;
}