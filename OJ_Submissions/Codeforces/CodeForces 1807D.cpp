#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v)  \
    for (auto &x : v) \
        cin >> x;
#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define range(v) v.begin(), v.end()
typedef long long int ll;

const double eps = 1e-9;
const int mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector<ll> v(n);
    ll orsum=0;
    for(auto &x:v){
        cin>>x;
        orsum+=x;
    }
    vector<ll> presum(n);
    presum[0]=v[0];
    for(int i=1;i<n;i++){
        presum[i]=presum[i-1]+v[i];
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        ll k;
        cin>>k;
        ll sum=0;
        if(l==0){
            sum=presum[r];
        }
        else{
            sum=presum[r]-presum[l-1];
        }
        ll ans=orsum-sum;
        //cout<<ans+(r-l+1)*k<<endl;
        ll val=ans + (r-l+1)*k;
        if(val & 1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
