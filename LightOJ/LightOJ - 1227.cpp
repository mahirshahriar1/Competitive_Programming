#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;



int kas=0;       
void solve()
{          
    int n,p,q;
    cin>>n>>p>>q;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    int sum=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]>q)
            break;
        sum+=arr[i];
        cnt++;
        if(cnt==p)
            break;
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
    cin.ignore();
    while(t--)
    {
        solve();
    }  



}
