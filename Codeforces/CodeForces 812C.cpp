#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007
typedef long long int ll;
const double eps=1e-9;


ll calc(ll n, ll k, const vector<ll>& arr)
{
    vector<ll> v2;
    for(ll i=0;i<n;i++)
    {
        ll temp=arr[i]+(i+1)*(k);
        v2.push_back(temp);
    }        
    
    sort(v2.begin(),v2.end());

    ll sum=0;

    for(ll i=0;i<k;i++)
        sum+=v2[i];
    return sum;
}



int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif

    ll n,s,temp;
    cin>>n>>s;

    vector<ll> arr;
    for(ll i=0;i<n;i++)
    {        
        cin>>temp;
        arr.push_back(temp);
    }       
    
    ll l=1, r=n,mid,res=0,sum=0;

    while(l<=r)
    {
        mid=(l+r)>>1;
        ll temp_sum=calc(n,mid,arr);
        if(temp_sum<=s){           
            sum=temp_sum;
            res=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<res<<' '<<sum<<endl;
    
    return 0;
}
