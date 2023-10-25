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

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int n,m;
char grid[300][300];
bool vis[300][300];
int s,w;
void dfs(int x,int y){   
    if(grid[x][y]=='k') s++;
    if(grid[x][y]=='v') w++;
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]!='#'){
            dfs(nx,ny);
        }
    }
}

int main(){
    fastio  

    cin>>n>>m;

    int sheep=0,wolf=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='k') sheep++;
            if(grid[i][j]=='v') wolf++;
        }
    }

    memset(vis,false,sizeof(vis));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]!='#'){
                s=0,w=0;
                dfs(i,j);
                if(s>w) wolf-=w;
                else sheep-=s;
            }
        }
    }
    cout<<sheep<<" "<<wolf<<endl;

}
