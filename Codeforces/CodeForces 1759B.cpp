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
    int n,s;
    cin>>n>>s;
    vector<int> v(n);
    takeInput(v);
    vector<int> temp=v;
    sort(range(temp));

    vector<int> miss;
    int mx=temp[n-1];
    for(int j=1;j<=mx;j++){
        auto itr=lower_bound(range(temp),j);
        if(itr!=temp.end()){
            int ind=itr-temp.begin();
            if(temp[ind]!=j){
                miss.push_back(j);
            }
        }
    }
    if(miss.size()==0){
        int sum=0;
        for(int i=mx+1;;i++){
            sum+=i;
            if(sum>=s){
                break;
            }
        }
        if(sum==s){
            cout<<"YES"<<endl;
            return;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }else{
        int sum=0;
        for(auto x:miss){
            sum+=x; 
        }
        if(sum==s){
            cout<<"YES"<<endl;
        }else{
            while(sum<s){
                mx++;
                sum+=mx;
            }
            if(sum==s){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
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
