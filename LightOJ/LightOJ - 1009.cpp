#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=20005;
int kas,vamp,lyk;
vector<int> g[N];
int color[N];

//vamp->1
//lyk ->0

void bfs(int src){
    if(g[src].size()==0) 
        return;

    queue<int> q;
    q.push(src);
    color[src]=1;
    vamp++;

    while(!q.empty()){
        int f=q.front();
        q.pop();

        for(int i=0;i<g[f].size();i++){
            int child=g[f][i];

            if(color[child]==-1){
                q.push(child);
                
                if(color[f]==1){
                    color[child]=0;
                    lyk++;
                }else{
                    color[child]=1;
                    vamp++;
                }
            }
        }
    }

}

void clear(){
    memset(color,-1,sizeof(color));
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
    while(t--)
    {
        clear();
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans=0;

        for(int i=1;i<N;i++){
            vamp=lyk=0;           
            if(color[i]==-1){
                bfs(i);
                int mx=max(vamp,lyk);
                ans+=mx;    
            }
        }
        cout<<"Case "<<++kas<<": "<<ans<<endl;        
    }

    return 0;
}
