#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,d,c=1;
    cin>>t;

    while(t--)
    {
        set <int> s;
        deque <int> v;
        int in,max=0;

        cin>>n>>d;

        for(int i=1;i<=n;i++)
        {
            cin>>in;
            s.insert(in);
            v.push_back(in);
            if(i>=d)
            {
                auto itr1=s.begin();
                auto itr2=prev(s.end());
                int temp=*itr2-*itr1;
                if(temp>max)
                    max=temp;
                auto itrr=s.find(v.front());
                if(itrr!=s.end())
                  s.erase(itrr);

                v.pop_front();
            }
        }
        s.clear();
        cout<<"Case "<<c++<<": "<<max<<endl;

    }

    return 0;
}

