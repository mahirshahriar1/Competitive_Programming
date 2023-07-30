#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=25e2+10;

vector<int> a(N);
int dp[N];

int LIS(int i){
    if(dp[i]!=-1) return dp[i];
    int ans=1;
    for(int j=0;j<i;j++){
        if(a[i]>a[j]){
            ans=max(ans,LIS(j)+1);
        }
    }
    return dp[i]=ans;
} //O(n^2)

int f(int i, vector<int> &A) {
    if (mem[i] != EMPTY_VALUE) {
        return mem[i];
    }
    
    int ans = 0;
    for (int j = i + 1;j < A.size();j++) {
        if (A[j] > A[i]) {
            ans = max(ans, f(j, A));
        }
    }
    
    mem[i] = ans + 1;
    return mem[i];
}

int mem[MAX_N];
int next_index[MAX_N];

int f(int i, vector<int> &A) {
    if (mem[i] != EMPTY_VALUE) {
        return mem[i];
    }
    
    int ans = 0;
    for (int j = i + 1;j < A.size();j++) {
        if (A[j] > A[i]) {
            int subResult = f(j, A);
            if (subResult > ans) {
                ans = subResult;
                next_index[i] = j;
            }
        }
    }
    
    mem[i] = ans + 1;
    return mem[i];
}

vector<int> findLIS(vector<int> A){
  int ans = 0;
  
  for(int i = 0;i<A.size();i++) {
      mem[i] = EMPTY_VALUE;
      next_index[i] = EMPTY_VALUE;
  }
  
  int start_index = -1;
  
  for(int i = 0;i<A.size();i++) {
      int result = f(i, A);
      if (result > ans) {
          ans = result;
          start_index = i;
      }
  }
   vector<int> lis;
  while(start_index != -1) {
      lis.push_back(A[start_index]);
      start_index = next_index[start_index];
  }
  return lis;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    //8     10 9 2 5 3 7 101 18       //ans is 4
    memset(dp,-1,sizeof(dp));

    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,LIS(i));
    }
    cout<<ans<<endl;

    return 0;
}
