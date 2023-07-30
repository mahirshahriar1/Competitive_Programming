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

 int n,w;
  ll weight[110];
  ll price[110];
  
  cin>>n>>w;
  for(int i=0;i<n;i++){
     cin>>weight[i]>>price[i];
  }
 
  // ll dp[2][100010];

  // for(int i=0;i<=w;i++){
  //    dp[0][i]=0;
  // }
  // for(int i=0;i<2;i++){
  //    dp[i][0]=0;
  // }
  // for(int i=1;i<=n;i++){
  //    for(int j=1;j<=w;j++){
  //       if(j>=weight[i-1]){
  //          dp[i&1][j]=max(dp[~i&1][j],dp[~i&1][j-weight[i-1]]+price[i-1]);
  //       }
  //       else{
  //          dp[i&1][j]=dp[~i&1][j];
  //       }
  //    }
  // }
  // cout<<dp[n&1][w]<<endl;


  ll dp[n+1][w+1];
  for(int i=0;i<=n;i++){
     for(int j=0;j<=w;j++){
        if(i==0 || j==0){
           dp[i][j]=0;
        }
        else if(j>=weight[i-1]){
           dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+price[i-1]);
        }
        else{
           dp[i][j]=dp[i-1][j];
        }
     }
  }
  cout<<dp[n][w]<<endl;

  // for(int i=0;i<=n;i++){
  //    for(int j=0;j<=w;j++){
  //       cout<<setw(3)<<dp[i][j]<<" ";
  //    }
  //    cout<<endl;
  // }
