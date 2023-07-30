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

struct node{
    int alex_w,alex_b, bob_w,bob_b;
};

vector<node> ans(1e6+1);
void sieve(){
    int num=1;
    ans[0]={0,0,0,0};

    bool turn1=true, turn2=false;
    int cnt=0,tmp=0;
    int order=1;
    for(int i=1;i<=1e6;i++){
        if(cnt==num){           
            cnt=0;
            num++;
            tmp++;  
            if(tmp==2) swap(turn1,turn2),tmp=0;
        }

        if(turn1){           
            if(order%2){
                // cout<<"alex_w order "<<order<<' '<<i<<endl;
                ans[i].alex_w=ans[i-1].alex_w+1;
                ans[i].alex_b=ans[i-1].alex_b;
                ans[i].bob_w=ans[i-1].bob_w;
                ans[i].bob_b=ans[i-1].bob_b;
                order++;
            }else{
                // cout<<"alex_b order "<<order<<' '<<i<<endl;
                ans[i].alex_w=ans[i-1].alex_w;
                ans[i].alex_b=ans[i-1].alex_b+1;
                ans[i].bob_w=ans[i-1].bob_w;
                ans[i].bob_b=ans[i-1].bob_b;
                order++;
            }
            if(cnt==num-1) swap(turn1,turn2);
            
        }else if(turn2){         
            if(order%2){
                // cout<<"bob_w order "<<order<<' '<<i<<endl;
                ans[i].alex_w=ans[i-1].alex_w;
                ans[i].alex_b=ans[i-1].alex_b;
                ans[i].bob_w=ans[i-1].bob_w+1;
                ans[i].bob_b=ans[i-1].bob_b;
                order++;
            }else{
                // cout<<"bob_b order "<<order<<' '<<i<<endl;
                ans[i].alex_w=ans[i-1].alex_w;
                ans[i].alex_b=ans[i-1].alex_b;
                ans[i].bob_w=ans[i-1].bob_w;
                ans[i].bob_b=ans[i-1].bob_b+1;
                order++;
            }     
            if(cnt==num-1) swap(turn1,turn2);
        }
        cnt++;
    }
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    sieve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n].alex_w<<' '<<ans[n].alex_b<<' '<<ans[n].bob_w<<' '<<ans[n].bob_b<<endl;
    }
    return 0;
}
