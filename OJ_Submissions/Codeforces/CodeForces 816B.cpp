#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    fastio;

    ll n,q,k,a,b;
    ll arr[200001];
     memset(arr, 0, sizeof(arr));
    cin>>n>>k>>q;

    while(n--)
    {
        ll temp1,temp2;cin>>temp1>>temp2;
        arr[temp1]++, arr[temp2+1]--;
    }
    for(int i=1;i<200001;i++)
        arr[i]+=arr[i-1];

     for(int i=1;i<200001;i++)
     {
         if(arr[i]>=k)
            arr[i]=1;
         else
            arr[i]=0;
         arr[i]+=arr[i-1];
     }
     while(q--)
     {
         cin>>a>>b;
         cout<<arr[b]-arr[a-1]<<endl;
     }


    return 0;
}
