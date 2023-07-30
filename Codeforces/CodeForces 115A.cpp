#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=2010;
vector<int> graph[N];
bool visited[N];

int mx;
void dfs(int node, int cnt){
	mx=max(mx,cnt);
	visited[node]=true;
	//cout<<node<<' '<<cnt<<endl;

	for(int i=0;i<graph[node].size();i++){
		int child=graph[node][i];
		if(!visited[child]){
			dfs(child,cnt+1);
		}
	}
}

int main(){
	fastio  
	#ifndef ONLINE_JUDGE  
		   freopen("input.txt", "r", stdin); 
		   freopen("output.txt", "w",stdout);
	#endif
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a!=-1)
			graph[a].push_back(i+1);
	}

	for(int i=0;i<n;i++){		
		memset(visited,false,sizeof(visited));
		dfs(i+1,1);
	}
	cout<<mx<<endl;

	return 0;

}
