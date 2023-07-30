#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

#define MAX_N 20
#define INF 99999999
#define EMPTY_VALUE -1

int w[MAX_N][MAX_N];
int mem[MAX_N];

int f(int u, int n) {  
    if (u == n - 1) {
        return 0;
    }
    
    if (mem[u] != EMPTY_VALUE) {
        return mem[u];
    }
    
    int ans = INF;
    for (int v = 0;v < n;v++) {
        if (w[u][v] != 0) {                     
            ans = min(ans, f(v, n) + w[u][v]);
        }
    }
    
    mem[u] = ans;
    return mem[u];
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
/*4 6
0 1 2
0 3 1
3 1 3
2 4 3
1 4 9
1 2 1
SAMPLE INPUT.. ans will be 6.. it is a DAG
*/


    memset(mem,-1,sizeof(mem));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,val;
        cin>>x>>y>>val;       
        w[x][y]=val;
    }

    cout<<f(0,5);



    return 0;
}
