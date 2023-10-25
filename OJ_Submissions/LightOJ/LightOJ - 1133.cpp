#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)
const double eps=1e-9;
#define mod 10000007

int kas=0;

void solve()
{
    int n,m;
    cin>>n>>m;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<m;i++)
    {
        char c;
        cin>>c;
        if(c=='S')
        {
            int d;  cin>>d;
            for(int i=0;i<n;i++)
                arr[i]+=d;
        }
        else if(c=='M')
        {
            int mul; cin>>mul;
            for(int i=0;i<n;i++)
                arr[i]*=mul;
        }
        else if(c=='D')
        {
            int div; cin>>div;
            for(int i=0;i<n;i++)
                arr[i]/=div;
        }   
        else if(c=='P')
        {
            int a,b; cin>>a>>b;
            swap(arr[a],arr[b]);
        }
        else{
            reverse(arr,arr+n);
        }
    }
    cout<<"Case "<<++kas<<":"<<endl;;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' '; 
    cout<<endl;

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
