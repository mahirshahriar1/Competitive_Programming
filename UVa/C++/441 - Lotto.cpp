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

    int n;
    bool flag=false;
    while(cin>>n,n!=0){
        if(flag)cout<<endl;
        vector<int> v(n);
        takeInput(v);
        
        for(int i=0;i<n;i++){            
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        for(int m=l+1;m<n;m++){
                            for(int o=m+1;o<n;o++){
                                cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<" "<<v[l]<<" "<<v[m]<<" "<<v[o]<<endl;
                            }
                        }
                    }
                }
            }
        }
        flag=true;
    }
}
