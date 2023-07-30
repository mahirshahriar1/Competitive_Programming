#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

int kas=0;
void solve()
{
    int n;
    cin>>n;

    map<int,int>m;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int temp; cin>>temp;
        v.push_back(temp);
    }
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        if(m[abs(v[i])]==0)
        {
            ans.push_back(v[i]);
            m[abs(v[i])]++;
        }
    }
    int sum=0;

    for(auto x: ans)
        sum+=x;
   
    cout<<"Case "<<++kas<<": "<<sum<<endl;


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
    while(t--)
    {
        solve();
    }  
    


}
