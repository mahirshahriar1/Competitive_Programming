#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

int dx[]={+1,-1,+0};
int dy[]={+0,-0,+1};

const int N=(int)2e5+10;
char grid[2][N];
bool visited [2][N];
int n,black;

bool isValid(int x,int y){
    return (x>=0 and x<2 and y>=0 and y<n 
        and !visited[x][y] and grid[x][y]=='B');
}
int bfs_cnt;
bool bfs(int node1,int node2){
    bfs_cnt++;
    memset(visited,false,sizeof(visited));

    visited[node1][node2]=true;
    queue<pair<int,int>> q;
    q.push({node1,node2});
    int cnt=0;
    while(!q.empty()){
        auto f=q.front();
        //cout<<"hoise-> "<<f.first<<' '<<f.second<<endl;
        cnt++;
        q.pop();
        for(int i=0;i<3;i++){
            int x=f.first+dx[i];
            int y=f.second+dy[i];
            //cout<<x<<' '<<y<<endl;
            if(isValid(x,y)){
                q.push({x,y});          
                visited[x][y]=true;
                break;
            }
        }
    }
  //cout<<endl;
    return (cnt==black);
}


void solve(){   
    black=0,bfs_cnt=0;
    cin>>n;
  
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            black+=(grid[i][j]=='B');    
        }
    }
    
    for(int i=0;i<n;i++){
        if(grid[0][i]=='B' or grid[1][i]=='B'){
            if(grid[0][i]=='B' and bfs(0,i)){
                cout<<"YES"<<endl;
                return;
            }
            if(grid[1][i]=='B' and bfs(1,i)){
                cout<<"YES"<<endl;
                return;
            }
            break;
        }      
    }
    cout<<"NO"<<endl;   

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
}
