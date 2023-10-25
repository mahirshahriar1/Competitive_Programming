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
    while(cin>>n, n!=0){
        vector<int> v(n);
        takeInput(v);

        int sum=0,tempsum=0;
    
        for(int i=0;i<n;i++){                      
            tempsum+=v[i];   
            sum=max({sum,tempsum});
            if(tempsum<0){               
                tempsum=0;
                continue;
            }             
        }
        sum=max(sum,tempsum);
        if(sum==0){
            cout<<"Losing streak."<<endl;
        }
        else{
            cout<<"The maximum winning streak is "<<sum<<"."<<endl;
        }

    }

}
