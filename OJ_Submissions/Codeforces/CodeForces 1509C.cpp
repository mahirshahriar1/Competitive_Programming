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


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;   
 
    bool flag=true;
    vector<int> t,m;
    for(int i=0;i<s.size();i++){
        if(s[i]=='M'){
            if(!t.size()){              
                flag=false;
                break;
            }else{
                t.erase(t.begin()); 
                m.push_back(i);              
            }
        }else{
            t.push_back(i);
        }
    }
    if(!flag ) goto end;
    for(int i=0;i<m.size();i++){      
        auto itr=upper_bound(range(t),m[i]);
        if(itr==t.end()){             
            flag=false;
            break;
        }
        t.erase(itr);
    }
    if(t.size()){
        flag=false;
    }
    end:
    cout<<(flag?"YES":"NO")<<endl;
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
