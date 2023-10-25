#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


void solve()
{
    int n,k;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;

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

    solve();

    return 0;
}


/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;

    vector <ll> v;

    for(int i=0;i<n;i++)
    {
        ll x;
        cin>> x;
        v.push_back(x);
    }

    ll k,j(0);
    cin>>k;

    for(int i=0;i<=n-k;i++)
    {
        ll max1=0;
        for(int j=i;j<i+k;j++)
        {
           max1=max(max1,v[j]);
        }
        cout<<max1<<" ";

    }

    return 0;
}

*/
