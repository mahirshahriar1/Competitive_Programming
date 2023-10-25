#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define len(v) (int)v.size()
#define range(v) v.begin(), v.end()
#define print(v) for (auto &x : v) cout << x << ' '; cout << endl;



void check(set<int> &indices, vector<int> &ans, vector<bool> &vis, int n)
{
    vector<int> res;

    for(int i=1;i<*indices.begin();i++){
        res.push_back(i);
    }

   
    for(auto &x:indices){
        res.push_back(x);
    }
  
    for(int i=*indices.begin()+1;i<=n;i++){
        if(!vis[i]) res.push_back(i);
    }
     
    if(ans.empty() or ans>res){
        swap(ans,res);
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n+1,{0,0});
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v.begin()+1,v.end());
       
    ll mx=-1;
    vector<int> opts;
    for(int i=n;i>=1;i--){
        ll area=v[i].first*1LL*(n-i+1);     
        if(area>mx){
            mx=area;
            opts.clear();
            opts.push_back(i);
        }else if(area==mx){
            opts.push_back(i);
        }
    }   
    
    vector<int> ans;
    set<int> indices;
    vector<bool> vis(n+1,0);

    for(int i=0,ind=n;i<len(opts);i++){
        while(ind>=opts[i]){ 
            indices.insert(v[ind].second);
            vis[v[ind].second]=1;
            ind--;
        }
        check(indices,ans,vis,n);
    }
    print(ans);

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
   
    return 0;
}