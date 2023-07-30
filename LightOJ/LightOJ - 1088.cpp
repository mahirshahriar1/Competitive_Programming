#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

int main()
{
    fastio;

    int t1,i=0;
    cin>>t1;

    while(t1--)
    {
        cout<<"Case "<<++i<<":"<<endl;
        int n,t2;
        cin>>n>>t2;

        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];

        while(t2--)
        {
            int a,b;
            cin>>a>>b;
            auto lower = lower_bound(v.begin(), v.end(), a)-v.begin();
            auto upper = upper_bound(v.begin(), v.end(), b)-v.begin();
            cout<<upper-lower<<endl;

        }

    }


    return 0;
}
