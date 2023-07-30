#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


void solve()
{
    int n,d;
    cin>>n>>d;

    deque<int> v;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());

    int cnt=0;
    while(!v.empty())
    {
        int x=v.back();
        int temp=x;
        v.pop_back();
        if(x>d)
        {
            cnt++;
        }
        else{
            while(!v.empty()&&x<=d)
                {
                    x+=temp;
                    v.pop_front();
                }
                if(x>d)
                {
                     cnt++;
                }

        }

    }
    cout<<cnt<<endl;


}

int main()
{
    fastio;

    solve();

    return 0;
}
