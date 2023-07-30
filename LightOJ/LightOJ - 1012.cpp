#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define range(v) v.begin(),v.end()
typedef long long int ll;

char arr[25][25];
bool vis[25][25];

int dx[]={+1,-1,+0,-0};
int dy[]={+0,-0,+1,-1};

int kas,cnt,w,h;

bool isvalid(int x, int y){
    return (x>=0 and x<h and y>=0 and y<w 
            and arr[x][y]!='#' and !vis[x][y]);
}

void dfs(int i,int j) {   
    vis[i][j] = true;
    cnt++;    

    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(isvalid(x,y)){
            dfs(x,y);
        }
    }
}


int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        cnt=0;
        memset(vis, false, sizeof(vis));      
        cin>>w>>h;
        int a,b;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='@'){
                    a=i,b=j;
                }
            }
        }
        
        dfs(a,b);
        cout<<"Case "<<++kas<<": "<<cnt<<endl;

    }

    return 0;
}
