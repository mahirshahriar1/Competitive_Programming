#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


void solve()
{
    int n;
    cin>>n;
    cout<<n<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<' ';
        arr[i]=i+1;
    }
    cout<<endl;

    int pnt=n-2;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(j==pnt)
            {
                swap(arr[j],arr[j+1]);
                pnt--;
            }
             cout<<arr[j]<<' ';
        }
        cout<<endl;
    }

}



int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;

}

