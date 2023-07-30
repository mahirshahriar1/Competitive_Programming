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

int main(){
     
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    string s;
    int kas=0;
    while(cin>>s){
        int n;
        cin>>n;
        cout<<"Case "<<++kas<<":"<<endl;;
        while(n--)
        {  
            int a,b;
            bool no=false;
            cin>>a>>b;
            if(a>b) swap(a,b);
            for(int i=a;i<b;i++){
                if(s[i]!=s[i+1]){
                    no=true;
                }
            }
            if(no){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }

        }
    }
    
        
}
