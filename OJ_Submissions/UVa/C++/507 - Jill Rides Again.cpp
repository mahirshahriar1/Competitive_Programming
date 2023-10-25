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

int kas;
void solve(){
    int n;
    cin>>n;
    
    int tmp = 1, s = 0, e=-1, sum = 0, ans = 0;
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        sum+=x;   
        if(sum<0) sum=0,tmp=i;
        if(sum>=ans){
            if(sum>ans || (sum==ans and (i-tmp>e-s)))
            {
                s=tmp;
                e=i;
            }
            ans=sum;
        }
    }  
    
    if(ans<=0) {
        cout<<"Route "<<++kas<<" has no nice parts\n";     
    }else{       
        cout<<"The nicest part of route "<<++kas<<" is between stops "<<s<<" and "<<e<<endl;     
    }
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    
    return 0;
}
