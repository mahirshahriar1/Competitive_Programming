#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps = 1e-9;


void solve()
{
    int n;
    cin>>n;
    int arr[(2*n)+1];
    vector<int>v;
    map<int,int>m;

    for(int i=0; i<2*n; i++)
    {
         cin>>arr[i];
        m[arr[i]]++;
         if(m[arr[i]]==1)
         {
             v.push_back(i);
         }

    }

    for(auto x:v)
        cout<<arr[x]<<" ";
    cout<<endl;

    m.clear();



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

