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
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int,int> ind;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ind[arr[i]]=i+1;
    }
    int sum=-1;

    for(auto itr1=ind.begin();itr1!=ind.end();itr1++){     
        for(auto itr2=ind.begin();itr2!=ind.end();itr2++){
            if(__gcd(itr1->first,itr2->first)==1){
                 //  cout<<itr1->first<<' '<<itr2->first<<endl;
                sum=max(sum,itr1->second+itr2->second);
            }
        }
    }
    cout<<sum<<endl;
    
 
}

int main()
{
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
      //  cout<<__gcd(2,3)<<endl;

}

