//https://imgur.com/a/ZiF18PA

#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


int main()
{
    fastio;

    int t,kas=0;
    cin>>t;

    double ab,ac,bc,rat;

    while(t--)
    {
        cin>>ab>>ac>>bc>>rat;

        double ans=sqrt(rat/(rat+1))*ab;

        printf("Case %d: %.6lf\n", ++kas, ans);

    }

    return 0;
}
