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

int sumofdigits(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> num(n);
    takeInput(num);
    set<int> ind;
    for(int i=0;i<n;i++){
        ind.insert(i+1);
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int l,r;
            cin>>l>>r;

            auto itr=ind.lower_bound(l);
            set<int> s;
            while(itr!=ind.end() && *itr<=r){
                num[(*itr)-1]=sumofdigits(num[(*itr)-1]);
                if(num[(*itr)-1]<10){
                    s.insert((*itr));
                }
                itr++;
            }
            for(auto x:s){
                ind.erase(ind.find(x));
            }
            
        }else{
            int x;
            cin>>x;
            cout<<num[x-1]<<endl;
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
