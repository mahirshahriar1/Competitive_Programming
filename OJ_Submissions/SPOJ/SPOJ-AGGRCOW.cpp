#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


bool canplacecows(vector<int> v, int cows, int d)
{
    cows--; //stall[0] one cow;
    int lastcow=0;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-v[lastcow]>=d)
        {
            cows--;
            lastcow=i;
        }
        if(cows==0)
            break;
    }
    return (cows==0);
}

int main()
{
    fastio;

    int t,n,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        vector<int> stalls(n);
        for(int i=0; i<n; i++)
            cin>>stalls[i];

        sort(stalls.begin(), stalls.end());

        int l=1, r=stalls.back();
        int res=1;
        while(l<=r)
        {
            int mid = (l + r) / 2;
            if (canplacecows(stalls,c,mid)){
                res=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        cout<<res<<endl;

    }


    return 0;
}
