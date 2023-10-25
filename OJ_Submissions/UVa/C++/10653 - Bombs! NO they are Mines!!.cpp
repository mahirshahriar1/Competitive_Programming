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

const int N= 1e3+10;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int arr[N][N];
int dist[N][N];

int r,c;

bool isvalid(int x,int y){  
    return (x>=0 and x<r and y>=0 and y<c
            and arr[x][y]==0 and dist[x][y]==-1);

}

void bfs(int sx,int sy) {
    queue <pair<int,int>> q;

    dist[sx][sy] = 0;
    q.push({sx,sy});    

    while (!q.empty()) {
        pair<int,int> f=q.front();   
        q.pop();

        for(int i=0;i<4;i++){
            int x=f.first+dx[i];
            int y=f.second+dy[i];
          
            if(isvalid(x,y)){
                dist[x][y]=dist[f.first][f.second]+1;             
                q.push({x,y});
            }
        }
    }

}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    while(cin>>r>>c){
        if(r==0 and c==0) break;

        memset(arr,0,sizeof(arr));
        memset(dist,-1,sizeof(dist));
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++){
            int row,bomb;
            cin>>row>>bomb;
           
            while(bomb--){
                int temp;
                cin>>temp;                
                arr[row][temp]=1;
            }
        }
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        
        bfs(sx,sy);
        cout<<dist[ex][ey]<<endl;
    }

    return 0;
}
