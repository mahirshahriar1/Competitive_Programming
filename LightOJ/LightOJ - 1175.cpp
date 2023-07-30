#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=210;

char graph[N][N];
int  fire[N][N];
int  jane[N][N];

int r,c,kas;

int dx[]={+1,-1,+0,-0};
int dy[]={+0,-0,+1,-1};

bool isValid(int x,int y){
    return (x>=0 and x<r and y>=0 and y<c 
            and graph[x][y]!='#');
}

bool boundary(int x,int y){
    return (x==0 or x+1==r or y==0 or y+1==c);
}

void bfs_fire(){
    queue<pair<int,int>> q;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(graph[i][j]=='F'){
                q.push({i,j});
                fire[i][j]=0;
            }
        }
    }
      
    while(!q.empty()){
        auto coord=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=coord.first+dx[i];
            int y=coord.second+dy[i];
            if(isValid(x,y) and fire[x][y]==-1){
                fire[x][y]=fire[coord.first][coord.second]+1;
                q.push({x,y});
            }
        }
    }
    //  for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<fire[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
}


void bfs(int a,int b){
    queue<pair<int,int>> q;

    q.push({a,b});
    jane[a][b]=0;

    while(!q.empty()){
        auto coord=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=coord.first+dx[i];
            int y=coord.second+dy[i];
            int dist=jane[coord.first][coord.second];
            if(isValid(x,y) and jane[x][y]==-1 
                and (fire[x][y]==-1 or fire[x][y]>dist+1)){
                jane[x][y]=dist+1;
                q.push({x,y});
            }
        }
    }
}


void solve(){
    cin>>r>>c;
    memset(fire,-1,sizeof(fire));
    memset(jane,-1,sizeof(jane));

    pair<int,int> s;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>graph[i][j];
            if(graph[i][j]=='J'){
                s.first=i,s.second=j;
            }
        }
    }

    bfs_fire();
    bfs(s.first,s.second);

    int ans=INT_MAX;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(boundary(i,j) and jane[i][j]!=-1){    
                ans=min(ans,jane[i][j]+1);
            }
        }
    }
    cout<<"Case "<<++kas<<": ";
    if(ans==INT_MAX){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<ans<<endl;
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
    while(t--)
    {
       solve();
    }

}
