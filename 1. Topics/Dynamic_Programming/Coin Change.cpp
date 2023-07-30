#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

#define MAX_N 20
#define MAX_W 10000

#define INF 99999999
#define EMPTY_VALUE -1

int C[MAX_N];
int mem[MAX_N][MAX_W];
int n;

int f(int i, int W) {
    if (W < 0) return INF;
    if (i == n) {
        if (W == 0) return 0;
        return INF;
    }
    
    
    if (mem[i][W] != EMPTY_VALUE) {
        return mem[i][W];
    }
    
    int res_1 = 1 + f(i + 1, W - C[i]);
    int res_2 = f(i + 1, W);
    
    mem[i][W] = min(res_1, res_2);
    
    return mem[i][W];
} //each coin only once use


int f(int i, int W) {
    if (W < 0) return INF;
    if (i == n) {
        if (W == 0) return 0;
        return INF;
    }
    
    if (mem[i][W] != EMPTY_VALUE) {
        return mem[i][W];
    }
    
    int res_1 = 1 + f(i, W - C[i]); //only this line updated
    int res_2 = f(i + 1, W);
    
    mem[i][W] = min(res_1, res_2);
    
    return mem[i][W];
} //unlimited use coin


int mem2[MAX_W];
int f_optimized(int W) {
    if (W < 0) return INF;
    if (W == 0) return 0;
    
    if (mem2[W] != EMPTY_VALUE) {
        return mem2[W];
    }
    
    int ans = INF;
    for (int i = 0;i < n;i++) {
        ans = min(ans, 1 + f_optimized(W - C[i]));
    }
    
    mem2[W] = ans;
    return mem2[W];
} //unlimited coin less memory


//NUMBER OF different WAYS TO MAKE A SUM

ll dp[7][30000+10];
ll func(ll ind , ll amount){
    if(amount==0) return 1;
    if(ind>=5) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];

    ll val=func(ind+1,amount);
    if(amount-arr[ind]>=0) val+=func(ind,amount-arr[ind]);
    return dp[ind][amount]=val;
}


int dp[7][10000];
int func(int ind , int amount){
    if(amount==0) return 1;
    if(ind<0) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];

    int ways=0;
    for(int coin=0;coin<=amount;coin+=arr[ind]){
        ways+=func(ind-1,amount-coin);
    }

    return dp[ind][amount]=ways;
}
//2 3 3 .. 3 2 3 these are not diff
/////////////////////////////////


//number of distinct ways to make a sum
vector<int> coins;

ll memo[1000000+10];
ll dpp(int x){
    if(x == 0) return 1;

    if(memo[x] != -1) return memo[x];

    ll ret = 0;
    for(int c : coins){
        if(x-c < 0) continue;
        ret += dpp(x-c);
        ret %= mod;
    }

    memo[x] = ret;

    return ret; 
} //2 3 3 .. 3 2 3 these are diff ways 
///


/* Knapsack */
int n;
int price[1100],weight[1010];

int dp[1100][40];

int knapsack(int i,int w){
    if(i>=n) return 0;

    if(dp[i][w]!=-1) return dp[i][w];

    int val1=0,val2=0;

    if(w-weight[i]>=0){
        val1=price[i]+knapsack(i+1,w-weight[i]);
    }
    val2=knapsack(i+1,w);
    
    return dp[i][w]=max(val1,val2);
}

/////


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
   
}
