#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n,m,s;
    char grid[50][50];
    bool visited[50][50];
    int gridcnt[50][50];
    while(cin>>n>>m>>s){
        if(n==0) break;           
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        memset(visited,false,sizeof(visited));
        memset(gridcnt,0,sizeof(gridcnt));

        bool loop=false;
        int x=0,y=s-1;
        int tot=0;
        int brek=0;
        while(true){
            if(x<0 || x>=n || y<0 || y>=m) break;
                       
            visited[x][y]=true;          
            if(grid[x][y]=='N') x--;
            else if(grid[x][y]=='S') x++;
            else if(grid[x][y]=='E') y++;
            else if(grid[x][y]=='W') y--;
            tot++;
            if(visited[x][y]){
                loop=true;
                brek=gridcnt[x][y];
                gridcnt[x][y]=tot;
                break;
            }
            gridcnt[x][y]=tot;
        }
    
        if(!loop)   cout<<tot<<" step(s) to exit"<<endl;
        else  cout<<brek<<" step(s) before a loop of "<<tot-brek<<" step(s)"<<endl;
        
    }

}
