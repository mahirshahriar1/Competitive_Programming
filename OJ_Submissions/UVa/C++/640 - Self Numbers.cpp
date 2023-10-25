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


const int N=1000000;
vector<bool> check(N+200,0);
void precompute(){
    for(int i=0;i<=N;i++){
        int x=i,y=i;
        while(y){
            x+=y%10;
            y/=10;
        }
        check[x]=1;
    }
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    precompute();

    for(int i=1;i<=N;i++){
        if(check[i]==0){
            cout<<i<<endl;
        }
    }
  
    return 0;

}
