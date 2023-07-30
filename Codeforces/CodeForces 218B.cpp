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

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int p,n;
    cin>>p>>n;

    priority_queue <int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq1.push(x),pq2.push(x);
    }
    
    int mx=0,mn=0;

    for(int i=0;i<p;i++){
        int x=pq1.top();
        mx+=x;
        pq1.pop();
        x--;
        if(x>0) pq1.push(x);
    }

    for(int i=0;i<p;i++){
        int x=pq2.top();
        mn+=x;
        pq2.pop();
        x--;
        if(x>0) pq2.push(x);
    }

    cout<<mx<<' '<<mn<<endl;

    return 0;
}
