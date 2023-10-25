#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=55;
char graph[N][N];
int  dist[N][N];
int r,c,kas;

// int dx[]={+1,-1,+0,-0};
// int dy[]={+0,-0,+1,-1};
int di[]={1,1,1,-1,-1,-1,0,0};
int dj[]={1,0,-1,1,0,-1,1,-1};

bool isValid(int x,int y){
    return (x>=0 and x<r and y>=0 and y<c);
}

int bfs(int i,int j){    
    dist[i][j]=0;
    queue<pair<int,int>> q;
    q.push({i,j});
    char c=graph[i][j];
    char next_alph=c+1;    

    while(!q.empty()){
        auto f=q.front();
        q.pop();
        next_alph=graph[f.first][f.second]+1; //had wa for mishandling this
        for(int k=0;k<8;k++){
            int x=f.first+di[k];
            int y=f.second+dj[k];

            if(isValid(x,y)){                  
                if(graph[x][y]==next_alph and dist[x][y]==-1){               
                    c=graph[x][y];                    
                    dist[x][y]=dist[f.first][f.second]+1;
                    q.push({x,y});
                }
            }
        }
    }
    return (c-'A'+1);
}

int main(){
    fastio  

    while(cin>>r>>c, r!=0 or c!=0){

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>graph[i][j];
        
        int ans=0;
        memset(dist,-1,sizeof(dist));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(graph[i][j]=='A' and dist[i][j]==-1){
                    int x=bfs(i,j);
                   // cout<<x<<' '<<i<<' '<<j<<endl;
                    ans=max(ans,x);
                }
            }
        }
        cout<<"Case "<<++kas<<": "<<ans<<endl;       
    }


}
