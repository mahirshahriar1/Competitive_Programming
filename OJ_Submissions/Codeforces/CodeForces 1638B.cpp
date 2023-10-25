#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    vector<int> even,odd;

    for(auto&x : arr){
        cin>>x;
        if(x%2)
            odd.push_back(x);
        else
            even.push_back(x);
    }

    bool oddsort=is_sorted(odd.begin(),odd.end()), evensort=is_sorted(even.begin(),even.end());

    if(oddsort&&evensort)   cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;  
 
}

int main(){
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
