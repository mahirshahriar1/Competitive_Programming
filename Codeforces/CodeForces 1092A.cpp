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
#define pb push_back
typedef long long int ll;
const double eps=1e-9;

string alph="abcdefghijklmnopqrstuvwxyz";
void solve()
{
    int a,b;
    cin>>a>>b;
    int n=a/b;
    int j=0;
    for(int i=1;i<=a;i++){
        cout<<alph[j++];
        if(i%b==0){
            j=0;
        }
    }
    cout<<endl;
}

int main()
{
    fastio

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
