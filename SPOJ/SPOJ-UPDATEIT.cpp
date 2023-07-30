#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


int main()
{
    fastio;

    int t;
    cin>>t;

    while(t--)
    {
        int n,u;
        cin>>n>>u;
        vector<int> arr(n,0);

        while(u--)
        {
            int l,r,val;

            cin>>l>>r>>val;
            arr[l]+=val;
            if(r+1<n)
                arr[r+1]-=val;
        }
        for(int i=1;i<n;i++)
            arr[i]+=arr[i-1];

        int q;cin>>q;
        while(q--)
        {
            int temp;
            cin>>temp;
            cout<<arr[temp]<<endl;
        }

    }


    return 0;

}
