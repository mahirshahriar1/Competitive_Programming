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
bool vis[105][105];
int r,c;
int cnt;

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool flag;

void dfs(int x,int y){
    vis[x][y]=true;
   

    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
      
        if(nx>=0 && nx<r && ny>=0 && ny<c
             && grid[nx][ny]=='*' && !vis[nx][ny]){ 
            return;            
        }
    }
    flag=true;

}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    while(cin>>r>>c){
        cnt=0;
        if(r==0 && c==0) break;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
            }
        }
        memset(vis,false,sizeof(vis));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='*' && !vis[i][j]){
                    flag=false;
                    dfs(i,j);
                    if(flag){
                        cnt++;                    
                    } 
                    memset(vis,false,sizeof(vis));
                }
            }
        }
        cout<<cnt<<endl;
    }
}
