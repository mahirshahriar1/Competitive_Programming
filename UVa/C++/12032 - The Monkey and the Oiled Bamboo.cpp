#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

vector<int> v;

int binarysearch(int key)
{
    int l=0, r=v.size()-1;
    int res=-1;
    while(l<=r){
        int mid = (l + r) / 2;
        if (v[mid] == key){
            res=mid;
            r=mid-1;
        }else if(v[mid]>key){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    return res;
}


int main()
{
    fastio;

    int T,n,kas=0;;
    cin>>T;

    while(T--)
    {
        int k=0;
        cin>>n;
        vector<int> v(n+10);
        v[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            if(v[i]-v[i-1]>k)
                k=v[i]-v[i-1];
        }
        int k2=k;
        for(int i=1;i<=n;i++)
        {
            if(v[i]-v[i-1]==k)
                k--;
            else if(v[i]-v[i-1]>k)
            {
                k2++;break;
            }
        }


        cout<<"Case "<<++kas<<": "<<k2<<endl;

    }

    return 0;
}
