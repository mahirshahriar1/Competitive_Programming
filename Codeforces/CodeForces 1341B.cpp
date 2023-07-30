#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


void solve()
{
    int n,k;
    cin>>n>>k;

    int arr[n+10];

    for(int i=1;i<=n;i++)
        cin>>arr[i];

    int max_peak=0;
    for(int i=2;i<k;i++)
    {
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
            max_peak++;
    }

    int last_peak=max_peak;
    int last_ind=1;

    for(int i=k+1;i<=n;i++)
    {
        int peak=last_peak;
        if(arr[i-k+1]>arr[i-k]&&arr[i-k+1]>arr[i-k+2])
            peak--;

        if(arr[i-1]>arr[i-2]&&arr[i-1]>arr[i])
            peak++;

        if(peak>max_peak)
        {
            last_ind=i-k+1;
            max_peak=peak;
        }
        last_peak=peak;
    }
    cout<<max_peak+1<<' '<<last_ind<<endl;



}

void solve2()
{
    int n,k;
    cin>>n>>k;

    int arr[n+10];

    for(int i=1;i<=n;i++)
        cin>>arr[i];

    int peaks[n+10]={0};


    for(int i=2;i<=n-1;i++)
    {
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
            peaks[i]=1;
    }

    for(int i=1;i<=n;i++)
        peaks[i]=peaks[i]+peaks[i-1];


    int last_ind=1, max_peak=0,val;

    for(int i=1;i+k-1<=n;i++)
    {
        val=peaks[i+k-2]-peaks[i];
        if(val>max_peak)
        {
            max_peak=val;
            last_ind=i;
        }

    }
    cout<<max_peak+1<<' '<<last_ind<<endl;

}

int main()
{
    fastio;

    int t;
    cin>>t;
    while(t--)
    {
        solve2();
    }



    return 0;
}
