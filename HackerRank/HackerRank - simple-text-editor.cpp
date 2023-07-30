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



int main()
{    
    fastio   

    int t;
    cin>>t;
    stack<string> stck;
    string s="";
    while(t--){
        int x;
        cin>>x;
        if(x==1){
            string tmp; cin>>tmp;
            stck.push(s);
            s+=tmp;
        }else if(x==2){
            int k; cin>>k;
            k=s.size()-k;
            stck.push(s);
            s=s.substr(0,k);
        }else if(x==3){
            int i; cin>>i;
            cout<<s[i-1]<<endl;
        }else{
            s=stck.top();
            stck.pop();
        }
    }
    return 0;

}
