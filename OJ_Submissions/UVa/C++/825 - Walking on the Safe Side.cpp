#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m;
bool grid[500][500];
int dp[500][500];
int dx[]={0,1};
int dy[]={1,0};

bool valid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int solve(int x,int y){
    if(x==n-1 && y==m-1) return 1;
    int &res=dp[x][y];
    if(res!=-1) return res;
    res=0;
    for(int i=0; i<2; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(valid(nx,ny) && grid[nx][ny]==false){
            res+=solve(nx,ny);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    bool newLine = false;
    while (t--){
        if(newLine) cout<<endl;
        memset(grid, 0, sizeof grid);
        memset(dp, -1, sizeof dp);

        cin >> n >> m;
        string s;
        cin.ignore();
        for(int i=0; i<n; i++){
            getline(cin, s);
            stringstream ss(s);
            int x, y;
            ss>>x;
            while(ss>>y){
                grid[x-1][y-1] = true;
            }
        }
        cout<<solve(0,0)<<endl;

        newLine = true;
    }

}