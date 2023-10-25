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

const int N=100000;
vector<int> graph[N];
vector<bool> visited(N);

stack <int> stk;
void topsort(int v) {
    visited[v] = true;

    for (auto u : graph[v])
        if (!visited[u])
            topsort(u);
    stk.push(v);
}

void dfs(int node) {  
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];       
        if (!visited[child]) {         
            dfs(child);
        }
    }
}

void cleargraph(){
    for(int i=0;i<N;i++){
        graph[i].clear();
    }
	visited.clear();
	while(!stk.empty()){
		stk.pop();
	}
}

int main() {
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    int n;
    cin>>n;
	int kas=0;

    while(n--){
		cleargraph();

        int nod,edge;
        cin>>nod>>edge;

        for (int i=0;i<edge;i++){
			int a, b;
			cin>>a>>b;       
			graph[a].push_back(b);       	 
  	  	}

		visited.assign(nod, false);

		for (int i = 1; i <= nod; i++)
			if (!visited[i])
				topsort(i);

		visited.assign(nod, false);	
	
		int cnt=0;

		while(!stk.empty()){
			auto v=stk.top();
			if (!visited[v]) {
				dfs (v);
				cnt++;         			
			}
			stk.pop();
		}	
			
		cout<<"Case "<<++kas<<": "<<cnt<<endl;
	}
    
}
