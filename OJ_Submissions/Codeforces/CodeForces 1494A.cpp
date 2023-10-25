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


bool isBalanced(string s){	
    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk.push(s[i]);
        else{
            if(stk.empty())
                return false;  
            else if(s[i]==')'&&stk.top()!='(')                
                return false; 
            else if(s[i]==']'&&stk.top()!='[')
                return false; 
            else if(s[i]=='}'&&stk.top()!='{')
              	return false; 
            stk.pop();
        }
    }
    if(stk.empty())
        return true;
    return false;
}

void solve(){
	string s;
	cin>>s;

	char start=s[0];
	if(s[0]==s.back()){
		cout<<"NO"<<endl;
		return;
	}

	char end=s.back();
	
	for(int i=0;i<s.size();i++){
		if(s[i]==start) s[i]='(';
		if(s[i]==end)  s[i]=')';
	}
	string a,b;
	a=b=s;
	for(int i=0;i<s.size();i++){
		if(isalpha(a[i]))
			a[i]=')';
	}
	for(int i=0;i<s.size();i++){
		if(isalpha(b[i]))
			b[i]='(';
	}

	if(isBalanced(a)||isBalanced(b)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
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
	   solve();
	}
	return 0;
}
