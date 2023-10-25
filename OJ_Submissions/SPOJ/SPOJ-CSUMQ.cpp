#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main()
{
    fastio;

    int n; cin>>n;

    vector <int> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector <int> prefix_sum(n);

    prefix_sum[0]=v[0];
    for(int i=1;i<n;i++)
         prefix_sum[i]=v[i]+prefix_sum[i-1];

    int q; cin>>q;

    while(q--)
    {
        int i,j,sum;
        cin>>i>>j;
        if(i==0)
             sum=prefix_sum[j];
        else
             sum=prefix_sum[j]-prefix_sum[i-1];
        cout<<sum<<endl;


    }

    return 0;

}
