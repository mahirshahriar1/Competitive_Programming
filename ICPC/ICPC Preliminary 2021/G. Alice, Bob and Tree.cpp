//https://algo.codemarshal.org/contests/icpc-dhaka-21-preli/problems/G


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

const int N=4e4;
vector<int> graph[N];
int color[N];
int weight[N];

void bfs_bicolor(int source) {
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
                continue;
            }
            if (color[child] == -1) {
                color[child] = 1-color[f];
                q.push(child);
            }
        }
    }       
}

void cleargraph(){
    for(int i=0;i<N;i++){
        graph[i].clear();
    }
    memset(color,-1,sizeof(color));
    memset(weight,0,sizeof(weight));
}

int kas;
void solve(){
    cleargraph();    
    int n;
    cin>>n;
    
    int a,b;
    for(int i=1;i<=n;i++)
        cin>>weight[i];   

    for(int i=0;i<n-1;i++){
        cin>>a>>b;          
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    bfs_bicolor(a);
    vector<int> v1,v2;
    for(int i=1;i<=n;i++){           
        if(color[i]==0)
            v1.push_back(weight[i]);
        else
            v2.push_back(weight[i]);
    }
    ll sum1=0,sum2=0;
    for(auto x:v1)        sum1+=x;
    for(auto x:v2)        sum2+=x;

    int cnt1=v1.size(),cnt2=v2.size();
    ll ans=-1;
    int ind=0;
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            ll temp=cnt1*weight[i]-sum1+sum2-cnt2*weight[i];
            if(temp>ans){
                ans=temp;
                ind=i;
            }
        }
        else{
            ll temp=cnt2*weight[i]-sum2+sum1-cnt1*weight[i];
            if(temp>ans){
                ans=temp;
                ind=i;
            }
        }
    }
    cout<<"Case "<<++kas<<": "<<ind<<endl;
}


int main(){
    fastio    
    
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
     
}
