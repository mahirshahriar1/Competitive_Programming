#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=25;
int dist[N][N];
char grid[N][N];
bool visited[N][N];
int r,c,kas;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool isValid(int x,int y){
    return (x>=0 and x<r and y>=0 and y<c and 
            !visited[x][y] and grid[x][y]!='#' and grid[x][y]!='m');
}

void bfs(int x,int y){
    queue<pair<int,int>> q;
    dist[x][y]=0;
    q.push({x,y});
    visited[x][y]=true;

    while(!q.empty()){
        pair<int,int> pnt=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nx=pnt.first+dx[i];
            int ny=pnt.second+dy[i];
            if(isValid(nx,ny)){
                visited[nx][ny]=true;
                q.push({nx,ny});
                dist[nx][ny]=dist[pnt.first][pnt.second]+1;
            }
        }
    }

}

void clear(){   
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dist[i][j]=-1;
            visited[i][j]=false;
        }
    }
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){      
        cin>>r>>c;
        vector<pair<int,int>> pos(3);
        pair<int,int> home;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='a')
                    pos[0].first=i,pos[0].second=j;
                else if(grid[i][j]=='b')
                    pos[1].first=i,pos[1].second=j;
                else if(grid[i][j]=='c')
                    pos[2].first=i,pos[2].second=j;
                else if(grid[i][j]=='h')
                    home.first=i,home.second=j;
            }
        }
        int mx=-1;

        for(int i=0;i<3;i++){
            bfs(pos[i].first,pos[i].second);
            mx=max(mx,dist[home.first][home.second]);
            clear();
        }
        cout<<"Case "<<++kas<<": "<<mx<<endl;

    }
}
