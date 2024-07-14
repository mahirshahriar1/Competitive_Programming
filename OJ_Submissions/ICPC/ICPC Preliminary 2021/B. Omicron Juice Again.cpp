#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


int main()
{
    fastio;
    int t,kas=0;
    cin>>t;
    while(t--)
    {
         int arr[3],k;
        cin>>arr[0]>>arr[1]>>arr[2]>>k;

        sort(arr,arr+3);

        int diff1=arr[1]-arr[0];
        int diff2=arr[2]-arr[1];
        int sum=arr[0]+arr[1]+arr[2];
        int val=sum/3;

        if(sum%3==0)
        {
            if((val-arr[0])%k==0&&(val-arr[1])%k==0&&(val-arr[2])%k==0)
                cout<<"Case "<<++kas<<": Peaceful"<<endl;
            else
                cout<<"Case "<<++kas<<": Fight"<<endl;
        }

        else
            cout<<"Case "<<++kas<<": Fight"<<endl;
    }


    return 0;
}

