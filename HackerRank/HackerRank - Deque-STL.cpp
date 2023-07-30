#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    deque <int> dq;

    int i=0;
    for(;i<k;i++)
    {
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for(;i<n;i++)
    {
       cout<<arr[dq.front()]<<' ';

        while(!dq.empty()&&dq.front()<=(i-k))
            dq.pop_front();

        while(!dq.empty()&&arr[i]>=arr[dq.back()])
            dq.pop_back();
       dq.push_back(i);

    }
    cout<<arr[dq.front()]<<' ';
    cout<<endl;

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
