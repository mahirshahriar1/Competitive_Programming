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

    vector<vector<set<int>>> v(201);
    for(int i=2;i<=200;i++){
        for(int j=2;j<=200;j++){
            for(int k=j+1;k<=200;k++){
                for(int l=k+1;l<=200;l++){
                    if(k*k*k+j*j*j+l*l*l==(i*i*i))
                    {
                        v[i].push_back({j,k,l});                       
                    }                       
                }
            }
        }
    }
    for(int i=1;i<=200;i++){
        if(v[i].size()>0){           
            vector<int> temp;
            for(auto x:v[i]){
                cout<<"Cube = "<<i<<", Triple = (";
                int xx=-1;
                for(auto y:x){
                    if(xx!=-1)                        
                        cout<<xx<<",";
                    xx=y;
                }
                cout<<xx<<")"<<endl;
            }
            
        }
    }
}
