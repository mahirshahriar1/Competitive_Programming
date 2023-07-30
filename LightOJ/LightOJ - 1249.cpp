#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps=1e-9;


int kas=0;       
void solve()
{        
    int n;
    cin>>n;
    vector<pair<int,string>> v;
    for(int i=0;i<n;i++)
    {
        string s;
        int a,b,c;
        cin>>s>>a>>b>>c;
        v.push_back({a*b*c,s});
    }  
    sort(v.begin(),v.end());
    cout<<"Case "<<++kas<<": ";
    if(v[0].first!=v[n-1].first)
        cout<<v[n-1].second<<" took chocolate from "<<v[0].second<<endl;
    else
        cout<<"no thief"<<endl;
    
}

int main()
{

    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        solve();
    }  



}
