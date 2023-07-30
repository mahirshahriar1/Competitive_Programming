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
    vector<int> arr(n),ans;
    int two_cnt=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
        int temp=arr[i];
        while(temp%2==0){
            two_cnt++;
            temp/=2;
        }
        
        temp=i+1;
        int val=0;
        while(temp%2==0){
            val++;
            temp/=2;
        }

        ans.push_back(val);
    }

    if(two_cnt>=n){
        cout<<0<<endl;
        return;
    }
    
    sort(range(ans));
    reverse(range(ans));
    
    int ops=0;
    for(auto x: ans){
        two_cnt+=x;
        ops++;
        if(two_cnt>=n){
            cout<<ops<<endl;
            return;
        }
    }
    cout<<-1<<endl;

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
   
    return 0;
}

