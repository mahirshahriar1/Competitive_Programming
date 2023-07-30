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

int GCD(int a, int b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}

int lcm(int a, int b){
    return (a/GCD(a,b))*b;
}

int main(){
     
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    int n,t;    
    
    while(true){
        cin>>n>>t;
        if(n == 0 && t==0) 
            break;        
        int coin[n];
        for(int i=0;i<n;i++)
            cin>>coin[i];   
        
        while(t--)
        {
            int mx=-INT_MAX,mn=INT_MAX;
            int table;
            cin>>table;            
            for(int i=0;i+3<n;i++){            
             for(int j=i+1;j+2<n;j++){
                for(int k=j+1;k+1<n;k++){
                    for(int l=k+1;l<n;l++){
                        int x = lcm(coin[i],lcm(coin[j],lcm(coin[k],coin[l])));
                            mx=max(mx,(table/x)*x);                             
                            mn=min(mn,((table/x)+((table%x==0)?0:1))*x);  
                            //cout<<((table/x)+((table%x==0)?0:1))*x<<endl;
                        }
                    }
                }                
            }
            cout<<mx<< ' '<<mn<<endl;            
          }

        }
       
        
        
}
