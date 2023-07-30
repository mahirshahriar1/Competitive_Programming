#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1,n2;

    cin>>n1;

    vector <ll> v;

    ll sum=0;
    for(int i=0;i<n1;i++)
    {
        ll x;
        cin>>x;
        sum+=x;
        v.push_back(sum);
    }
    cin>>n2;

    for(int i=0;i<n2;i++)
    {
        ll x;
        cin>>x;

        cout<<(lower_bound(v.begin(), v.end(), x)-v.begin())+1<<endl;

    }


    return 0;
}
