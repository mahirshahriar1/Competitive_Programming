#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


bool isSorted(int arr[],int n)
{
    for(int i=1; i<n; i++)
        if(arr[i]<arr[i-1])
            return false;
    return true;
}

void solve()
{


}

int main()
{
    //fastio;

    //solve();

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    bool ans=false;

    if(isSorted(arr,n))
    {
        cout<<"YES"<<endl;
        return 0;
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                swap(arr[i],arr[j]);
                if(!isSorted(arr,n))
                {
                    swap(arr[i],arr[j]);
                }
                else
                {
                    ans=true;
                    break;
                }
            }
        }
        if(ans)
            break;
    }
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
