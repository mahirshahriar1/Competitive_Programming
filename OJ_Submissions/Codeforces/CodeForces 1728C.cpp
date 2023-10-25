#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;
    
int len(int x)
{  
    return (int)log10(x)+1;
}

solve()
{
    int n;
    cin>>n;
    vector<int> v1(n), v2(n);
    priority_queue<int> pq1,pq2;

    for(auto& x: v1)
    {
        cin>>x;
        pq1.push(x);
    }
    for(auto& x: v2)
    {
        cin>>x;
        pq2.push(x);
    }
  
    int cnt=0;

    while(!pq1.empty()&&!pq.empty())
    {
        int a=pq1.top();
        int b=pq2.top();
        if(a==b)
        { 
            pq1.pop();
            pq2.pop();
        }
        else if(a>b)
        {
            pq1.pop();
            pq1.push(len(a));
            cnt++;
        }
        else if(a<b)
        {
            pq2.pop();
            pq2.push(len(b));
            cnt++;
        }
    }
    
    cout<<cnt<<endl;


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
    
