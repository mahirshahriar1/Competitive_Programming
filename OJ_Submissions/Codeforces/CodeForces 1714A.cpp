#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    fastio;

    int t;cin>>t;
    while(t--)
    {
        int x,H,M,i=0;
        cin>>x>>H>>M;
       vector<int> timee;
        while(x--)
        {
            int a,b;
            cin>>a>>b;
           timee.push_back(a*60+b);
        }
        sort(timee.begin(),timee.end());

        int time1=H*60+M,time2;

        auto itr=lower_bound(timee.begin(),timee.end(), time1);

        if(itr!=timee.end())
            time2=*itr;
        else
            time2=*(timee.begin());

        if(time2>=time1)
            cout<<abs(time1-time2)/60<<" "<<abs(time1-time2)%60<<endl;
        else
           cout<<abs(1440-time1+time2)/60<<" "<<abs(1440-time1+time2)%60<<endl;

    }


}



/*#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {

        int n, H, M;
        cin>>n>>H>>M;

        int ans = 5000; // large number

        for (int i = 0; i < n; i++)
        {
            int h, m;
            cin>>h>>m;

            int alarm = h * 60 + m;
            int slept = H * 60 + M;

            if (alarm < slept)
                ans = min(ans, alarm+(24*60)-slept);
            else
                ans = min(ans, alarm-slept);

        }

        cout<<ans / 60<<" "<<ans % 60<<endl;

    }


}
*/
