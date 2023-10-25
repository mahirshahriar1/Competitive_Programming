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

const int N=1e3;
vector<int> graph[N];
int color[N];

bool bfs_bicolor(int source) {
    memset(color, -1, sizeof(color));
    queue <int> q;
    color[source] = 1;
    q.push(source);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i = 0; i < graph[f].size(); i++) {
            int child = graph[f][i];
            if(color[f]==color[child]){
                return false;
            }
            if (color[child] == -1) {
                color[child] = 1-color[f];
                q.push(child);
            }
        }
    }
    return true;
   
}

void cleargraph(){
    for(int i=0;i<N;i++){
        graph[i].clear();
    }
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n;
    while(cin>>n , n!=0){
        cleargraph();
        int l,start;
        cin>>l;
        bool flag=true;
        int a,b;
        while(l--){          
            cin>>a>>b;          
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if(bfs_bicolor(a)){
            cout<<"BICOLORABLE."<<endl;
        }else{
            cout<<"NOT BICOLORABLE."<<endl;
        }

    }

}
