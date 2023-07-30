#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)


int kas=0;

void solve()
{       
    int n,val,incr;
    cin>>n;
    int arr[n],cnt=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];        
    
    int comp=2;
    for(int i=0;i<n;i++)
    {   
        if(arr[i]-comp>0)
            cnt+=ceil((arr[i]-comp)/5.0);
        comp=arr[i];
    }
    cout<<"Case "<<++kas<<": "<<cnt<<endl;
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
   
    return 0;
}
 
