#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;


int dx[]={+1,-1,+0,-0};
int dy[]={+0,-0,+1,-1};

vector<string> graph;
bool visited[35][101];

void dfs(int i,int j,char color){
	if(visited[i][j]) return;
	if(graph[i][j]=='X') return;
	visited[i][j]=true;
	graph[i][j]=color;
	for(int k=0;k<4;k++){
		int x=i+dx[k];
		int y=j+dy[k];	
		if(x>0 and x<graph.size() and y>0 and y<graph[x].size())
			dfs(x,y,color);		
	}
}

int main(){
	fastio  
	#ifndef ONLINE_JUDGE  
		   freopen("input.txt", "r", stdin); 
		   freopen("output.txt", "w",stdout);
	#endif
	

	string s;
	bool flag=false;

	while(true)
	{	
		while(true){	
			if(!getline(cin,s)) return 0;		
						
			if(s=="_____________________________" ){
				break;
			}
			graph.push_back(s);		
		
		}		
		memset(visited,false,sizeof(visited));
		
		for(int i=0;i<graph.size();i++){
			string x=graph[i];
	
			for(int k=0;k<x.size();k++){
				if(x[k]!='X' && x[k]!=' '){			
					dfs(i,k,x[k]);
				}
			}			
		}

		for(int i=0;i<graph.size();i++){
			cout<<graph[i]<<endl;
		}
		cout<<"_____________________________\n";
		flag=true;
		graph.clear();				
	}
	return 0;
}
