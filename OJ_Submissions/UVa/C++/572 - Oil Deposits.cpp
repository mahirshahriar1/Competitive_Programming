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

int n,m,cnt;
char graph[105][105];

int di[]={1,1,1,-1,-1,-1,0,0};
int dj[]={1,0,-1,1,0,-1,1,-1};

bool vis[105][105];

bool isvalid(int x,int y){
    return (x>=0 and x<n and y>=0 and y<m 
            and !vis[x][y]);
}

void dfs(int i,int j) {  
    vis[i][j] = true;        

    for(int k=0;k<8;k++){
        int x=i+di[k];
        int y=j+dj[k];
        if(isvalid(x,y)){    
            vis[x][y]=true;   
            if(graph[x][y]=='@')     
                 dfs(x,y);
        }
    }
}



int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif  
    while(cin>>n>>m){
        if(m==0) break;      
        cnt=0;
        memset(vis, false, sizeof(vis));  

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) 
                cin>>graph[i][j];
      

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){            
                if(graph[i][j]=='@' and vis[i][j]==false){
                    cnt++;                   
                    dfs(i,j);
                }
                    
            } 
        } 
        cout<<cnt<<endl;
           
        
    }
    
}
