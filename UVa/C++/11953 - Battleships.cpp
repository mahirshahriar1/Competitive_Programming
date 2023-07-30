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

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const int di[]={1,-1,0,0,1,1,-1,-1};
const int dj[]={0,0,1,-1,1,-1,1,-1};


char grid[105][105];
bool vis[105][105];

void dfs(int x,int y){
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];       
        if(nx>=0 && nx<100 && ny>=0 && ny<100 && !vis[nx][ny] &&         
        (grid[nx][ny]==grid[x][y] || grid[nx][ny]==(grid[x][y]=='x'?'@':'x'))){
            dfs(nx,ny);
        }
    }
}

int kas;
void solve(){
    int n;
    cin>>n;
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            //cout<<grid[i][j]<<" ";
        }
       // cout<<endl;
    }
    memset(vis,false,sizeof(vis));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] and grid[i][j]=='x'){
                //cout<<i<<" "<<j<<endl;
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<"Case "<<++kas<<": "<<ans<<endl;

}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
