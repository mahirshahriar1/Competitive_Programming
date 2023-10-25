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

int grid[100][100];
int cnt,n;
bool visited[100][100];
int di[]={1,1,1,0,0,-1,-1,-1};
int dj[]={1,0,-1,1,-1,1,0,-1};

bool isValid(int x , int y){
    return (x>=0 and x<n and y>=0 and y<n and grid[x][y]==1 and !visited[x][y]);
}

void dfs(int x,int y){
   
    visited[x][y]=true;

    for(int i=0;i<8;i++){
        int a=x+di[i];
        int b=y+dj[i];
        if(isValid(a,b)){
           //cout<<a<<' '<<b<<' '<<grid[a][b]<<endl;
            dfs(a,b);
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
   
    while(cin>>n)
    {   
        cnt=0;
        memset(visited,false,sizeof(visited));
        int x=0;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++){
                grid[x][j]=s[j]-'0';
            }
            x++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
               // cout<<grid[i][j];
                if(!visited[i][j] and grid[i][j]){
                    cnt++;                   
                    dfs(i,j);
                }
            }            
        }

        cout<<"Image number "<<++kas<<" contains "<<cnt<<" war eagles."<<endl;
    }
}
