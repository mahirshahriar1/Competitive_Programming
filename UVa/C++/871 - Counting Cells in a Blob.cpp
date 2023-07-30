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

int grid[30][30];
bool vis[30][30];
int n,m;

const int di[]={-1,-1,-1,0,0,1,1,1};
const int dj[]={-1,0,1,-1,1,-1,0,1};

int cnt;
void dfs(int i,int j){
    if(i<0 || j<0 || i>=n) return;
    if(vis[i][j] || grid[i][j]==0) return;
    vis[i][j]=true;
    cnt++;
    for(int k=0;k<8;k++){
        dfs(i+di[k],j+dj[k]);
    }

}
bool flag=true;
void solve(){

    string s;
    vector<string> v;
    if(flag){
        getline(cin,s);
        flag=false;
    }

    while(getline(cin,s)){
        
        if(s=="") break;        
        v.push_back(s);
    }
    n=v.size();    
  
    memset(grid,0,sizeof(grid));
    memset(vis,false,sizeof(vis));

    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){          
            grid[i][j]=v[i][j]-'0';            
        }     
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            if(grid[i][j]==1 && !vis[i][j]){
                cnt=0;
                dfs(i,j);
                ans=max(ans,cnt);
            }
        }
    }
    cout<<ans<<endl;   

}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
       solve();
       if(t>=1) cout<<endl;
    } 
    return 0;
}
