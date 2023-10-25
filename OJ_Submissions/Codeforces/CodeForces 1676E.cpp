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

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    takeInput(v); 
    sort(v.rbegin(),v.rend());

    vector<int> pre_sum(n+1);
    pre_sum[0]=0;
    for(int i=0;i<n;i++){
        pre_sum[i+1]=v[i]+pre_sum[i];
    }
    reverse(range(v));
    //print(pre_sum)
    while(k--){
        int tar;
        cin>>tar;

        auto itr=lower_bound(range(v),tar);
     
        if(itr!=v.end()&&*itr==tar){
               cout<<1<<endl;
        }
        else{
            auto itr=lower_bound(range(pre_sum),tar);
            if(itr!=pre_sum.end()){
                if(*itr>=tar){                       
                    cout<<itr-pre_sum.begin()<<endl;     
                }else{
                    cout<<-1<<endl;
                }
            }else{
                cout<<-1<<endl;
            }
        }
        
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
