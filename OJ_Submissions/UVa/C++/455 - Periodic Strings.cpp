#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
        cin.ignore();
    bool p=false;
    while(t--){
        if(p) cout<<endl;
        string s;
        getline(cin,s);
        getline(cin,s);       
        bool ans=false;
        for(int i=1;i<s.size();i++){
            bool flag=true;
            string tmp=s.substr(0,i);
            for(int j=i;j<s.size();j+=i){
                if(s.substr(j,i)!=tmp){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans=true;
                cout<<tmp.size()<<endl;
                break;
            }
        }
        if(!ans)        cout<<s.size()<<endl;
        p=true;
        
    }
}
