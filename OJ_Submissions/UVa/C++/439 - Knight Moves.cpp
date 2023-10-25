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

const int N= 8;

// All possible moves of a knight
const int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


int dist[N][N];

bool isvalid(const int &x, const int &y){  
    return (x>=0 and x<8 and y>=0 and y<8 and dist[x][y]==-1);
}

void bfs(int sx,int sy) {
    queue <pair<int,int>> q;
    dist[sx][sy]=0;
    q.push({sx,sy});    

    while (!q.empty()) {
        pair<int,int> f=q.front();
        q.pop();
        for(int i=0;i<8;i++){
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
    string a,b;
    while(cin>>a>>b){
       memset(dist,-1,sizeof(dist));
       int sx=a[0]-'a';
       int sy=a[1]-'1';
       int ex=b[0]-'a';
       int ey=b[1]-'1';
       bfs(sx,sy);       

       cout<<"To get from "<<a<<" to "<<b<<" takes "<<dist[ex][ey]<<" knight moves."<<endl;
    }
    
    return 0;
}
