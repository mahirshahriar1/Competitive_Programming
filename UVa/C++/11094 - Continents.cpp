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

char grid[100][100];
int cnt,m,n;
bool visited[100][100];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char c;

bool isValid(int x , int y){
    return (x>=0 and x<m and y>=0 and y<n and grid[x][y]==c and !visited[x][y]);
}

int cnt2;
void dfs(int x,int y){
    visited[x][y]=true;
    cnt2++;
   // cout<<x<<" "<<y<<" "<<cnt2<<endl;
    
    for(int i=0;i<4;i++){
        int a=x+dx[i];
        int b=y+dy[i];

        if(b==n) b=0; else if(b==-1) b=n-1;

        if(isValid(a,b)){     
            dfs(a,b);
            //cout<<a<<" "<<b<<" "<<ans<<endl;
        }
    }
   
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int kas=0;
   
    while(cin>>m>>n)
    {   
        memset(visited,false,sizeof(visited));
        cnt=0;

        for(int i=0;i<m;i++){            
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        int x,y;
        cin>>x>>y;
        c=grid[x][y];
        dfs(x,y);
       
        for(int i=0;i<m;i++){            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==c and !visited[i][j]){                    
                    cnt2=0;
                    dfs(i,j);
                    cnt=max(cnt,cnt2);
                }
            }
        }
        cout<<cnt<<endl;

    }
}
