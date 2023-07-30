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

map <string, vector<string>> graph;
map <string, string> par;
map <string, int> dist;

int bfs(const string& source,const string& dest){
	dist[source]=0;
	queue<string> q;
	q.push(source);

	while(!q.empty()){
		string f=q.front();
		q.pop();
		
		if(f==dest){
			return dist[f];
		}

		for(int i=0;i<graph[f].size();i++){
			string child=graph[f][i];

			if(dist[child]==-1) //unvisited
			{
				dist[child]=dist[f]+1;
				par[child]=f;
				q.push(child);
			}
		}		
	}
	return -1;	
}

void clearGraph(){
	graph.clear();
	par.clear();
	dist.clear();
}

void printpath(const string& source, const string& dest){
	vector<string> end,start;
		string x=dest;
		while(x!=source){
			end.push_back(x);
			x=par[x];
			start.push_back(x);
		}

		reverse(end.begin(), end.end());
		reverse(start.begin(), start.end());

		for(int i=0;i<end.size();i++){
			cout<<start[i]<<' '<<end[i]<<endl;
		}
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

	int x;
	bool flag=false;
	while(cin>>x){
		if(flag) cout<<endl; flag=true;

		clearGraph();
		string a,b;
		for(int i=0;i<x;i++){
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);

			dist[a]=-1;
			dist[b]=-1;
		}

		string source,dest;
		cin>>source>>dest;

		if(bfs(source,dest)!=-1){
			printpath(source,dest);
		}else{
			cout<<"No route"<<endl;
		}

	}
	
    return 0;
}
