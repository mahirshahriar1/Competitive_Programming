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


void solve()
{

}

int main()
{
    fastio

    int n;

    cin>>n;
    vector<int> v(n);
    takeInput(v);
    vector<int> arr=v;
    sort(range(arr));
    int t=n,i=0;
    while(t--){
        if(arr.back()==v[i]){
            cout<<arr[n-2]<<endl;
        }else{
            cout<<arr.back()<<endl;
        }
        i++;
    }

    return 0;
}
