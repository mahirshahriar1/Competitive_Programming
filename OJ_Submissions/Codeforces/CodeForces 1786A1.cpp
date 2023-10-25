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
    int alex, bob;
};

vector<node> ans(1e6+1);
void sieve(){
    int num=1;
    ans[0]={0,0};

    bool turn1=true, turn2=false;
    int cnt=0,tmp=0;
    for(int i=1;i<=1e6;i++){
        if(cnt==num){           
            cnt=0;
            num++;
            tmp++;           
            if(tmp==2) swap(turn1,turn2),tmp=0;
        }

        if(turn1){           
            ans[i].alex=ans[i-1].alex+1;
            ans[i].bob=ans[i-1].bob;
            if(cnt==num-1) swap(turn1,turn2);        
            
        }else if(turn2){         
            ans[i].alex=ans[i-1].alex;
            ans[i].bob=ans[i-1].bob+1;
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
        cout<<ans[n].alex<<" "<<ans[n].bob<<endl;
    }
    return 0;
}
