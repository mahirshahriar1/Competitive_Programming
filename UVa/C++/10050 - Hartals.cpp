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

    int test;
    cin>>test;
    while(test--){
        int d;
        cin>>d;
        int n;
        cin>>n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }

        bool arr[d+1];
        memset(arr,1,sizeof(arr));
     
        for(int i=1;i<=n;i++){
            
            for(int j=v[i];j<=d;j+=v[i]){
               
                arr[j]=false;
            }

        }
        int cnt=0;
        int x=0;
        for(int i=1;i<=d;i++){
            x++;
            if(arr[i]==false){  
                cnt++;
            }
            if(x%5==0){              
                i+=2;
            }
        }             
        cout<<cnt<<endl;

    }
    
    
    return 0;
}
