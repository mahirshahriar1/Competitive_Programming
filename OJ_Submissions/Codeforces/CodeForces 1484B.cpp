#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;


void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    takeInput(v);
    if(n<=2)
    {
        cout<<0<<endl;
        return;
    }

    set<int>s;
    int mx=v[0];
    for(int i=1;i<n;i++)
    {
        s.insert(v[i]-v[i-1]);
        mx=max(v[i],mx);
    }
    if(s.size()>2)
    {
        cout<<-1<<endl;
        return;
    }
    if(s.size()==1)
    {
        cout<<0<<endl;
        return;
    }
    int a=*s.begin();
    s.erase(s.begin());
    int b=*s.begin();
    if(a>=0&&b>=0)
    {
        cout<<-1<<endl;
        return;
    }
    if(a<=0&&b<=0)
    {
        cout<<-1<<endl;
        return;
    }
    if(a<b) swap(a,b);

    if(mx>a-b)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<a-b<<' '<<a<<endl;

        

}

int main()
{
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

 
}
