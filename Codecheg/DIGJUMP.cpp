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

bool visited[(int)1e5+100];
bool used[20];
int dist[(int)1e5+100];

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    string s;
    cin>>s;
    vector<int> graph[10];
    for(int i=0;i<s.size();i++){
        graph[s[i]-'0'].push_back(i);
    }

    queue<int> q;
    int n=s.size();
    
    memset(visited,false,sizeof(visited));
    memset(used,false,sizeof(used));
    memset(dist,0,sizeof(dist));
    
    q.push(0);
    visited[0]=true;

    while(!q.empty()){
        int ind=q.front();
        q.pop();
        if(!used[s[ind]-'0']){
            for(int i=0;i<graph[s[ind]-'0'].size();i++){
                int x=graph[s[ind]-'0'][i];              
                if(!visited[x]){
                    visited[x]=true;
                    dist[x]=dist[ind]+1;                    
                    q.push(x);
                }
            }
            used[s[ind]-'0']=true;
        }
        if(ind+1<n and !used[s[ind+1]-'0']){
            if(!visited[ind+1]){
                visited[ind+1]=true;
                dist[ind+1]=dist[ind]+1;              
                q.push(ind+1);
            }
        }
        if(ind-1>=0 and !used[s[ind-1]-'0']){
            if(!visited[ind-1]){
                visited[ind-1]=true;
                dist[ind-1]=dist[ind]+1;
                q.push(ind-1);
            }
        }
    }

    cout<<dist[n-1]<<endl;

    return 0;
}
