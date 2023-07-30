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

char grid[105][105];
int cnt;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m,s;
vector<char> dir;

bool isValid(int i,int j){
  if(i<0||j<0||i>=n||j>=m) return false;
  if(grid[i][j]=='#') return false;
  return true;
}

void dfs(int i,int j, char c, int n){
  if(grid[i][j]=='*'){
    cnt++;
    grid[i][j]='.';
  }
  if(n==s) return;
 
  if(dir[n]=='F'){
     int x=0;
        if(c=='N') x=3;
        else if(c=='L') x=0;
        else if(c=='S') x=2;
        else if(c=='O') x=1;

        if(isValid(i+dx[x],j+dy[x])){
          dfs(i+dx[x],j+dy[x],c,n+1);
        }
        else{
          dfs(i,j,c,n+1);
        }
  }else if(dir[n]=='D'){
      if(c=='N') dfs(i,j,'L',n+1);
      else if(c=='L') dfs(i,j,'S',n+1);
      else if(c=='S') dfs(i,j,'O',n+1);
      else if(c=='O') dfs(i,j,'N',n+1);
  }
  else if(dir[n]=='E'){
      if(c=='N') dfs(i,j,'O',n+1);
      else if(c=='O') dfs(i,j,'S',n+1);
      else if(c=='S') dfs(i,j,'L',n+1);
      else if(c=='L') dfs(i,j,'N',n+1);
  }

}


int main(){
  fastio  
  #ifndef ONLINE_JUDGE  
         freopen("input.txt", "r", stdin); 
         freopen("output.txt", "w",stdout);
  #endif


  while(cin>>n>>m>>s){
    if(n==0&&m==0&&s==0) break;
    cnt=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>grid[i][j];     
      }
    }
    dir.clear();
    for(int i=0;i<s;i++){
      char c;
      cin>>c;
      dir.push_back(c);
    }
  
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(grid[i][j]=='N'||grid[i][j]=='S'||grid[i][j]=='L'||grid[i][j]=='O'){          
            dfs(i,j,grid[i][j],0);
          }
      }
    }
    cout<<cnt<<endl;
    
  }
}
