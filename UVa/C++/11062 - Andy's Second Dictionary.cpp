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



int main(){
	fastio  
	#ifndef ONLINE_JUDGE  
		   freopen("input.txt", "r", stdin); 
		   freopen("output.txt", "w",stdout);
	#endif

	set<string> s;

	string str;

	string temp="";
	while(getline(cin,str)){
		
		for(int i=0;i<str.length();i++){
			
			if(isalpha(str[i])){
				temp+=str[i];
			}
			else{
				if(str[i]=='-'){
					if(i+1!=str.length()){						
						temp+=str[i];
					}					
				}
				else if(temp!=""){
					transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
					s.insert(temp);
					temp="";
				}
			}
		}
		if(str[str.length()-1]!='-' and temp!=""){
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			s.insert(temp);
			temp="";
		}
				
	}
	for(auto x:s){	
		cout<<x<<endl;
	}

	return 0;
}
