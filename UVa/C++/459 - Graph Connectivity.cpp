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

const int N = 1000;

vector <int> g[ N ];
bool visited[ N ];
void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < g[node].size(); i++) {
        int child = g[node][i]; 
        if (!visited[child]) {          
            dfs(child);
        }
    }
}
void cleargraph(){
    for(int i=0;i<N;i++){
        g[i].clear();
    }
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
  
    bool end=false;
    while(t--){
        
        if(end) cout<<endl;
        else    end=true;        

        char c;
        cin>>c;        
        int mx=c-'A'+1;
        cin.ignore();

        memset(visited,false,sizeof(visited));
        cleargraph();

        string s;
        while(getline(cin,s), s!=""){   
            int a=s[0]-'A'+1;
            int b=s[1]-'A'+1;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        ll cnt=0;
        for(int i=1;i<=mx;i++){
            if(!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        cout<<cnt<<endl;
    }

}
