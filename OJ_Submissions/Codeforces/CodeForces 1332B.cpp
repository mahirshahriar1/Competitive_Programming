#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
     fastio;
    int t1;
    cin>>t1;

    while(t1--)
    {
        vector <pair<int,int>> primes= {{2,-1},{3,-1},{5,-1},{7,-1},{11,-1},
                                        {13,-1},{17,-1},{19,-1},{23,-1},{29,-1},{31,-1}};
        int cnt=1;
        int t2;
        cin>>t2;
        vector<int> v;
        vector<int> ans;
        for(int i=0; i<t2; i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        for(int i=0; i<t2; i++)
        {
            for(int j=0; j<11; j++)
            {
                if(v[i]%primes[j].first==0)
                {
                    if(primes[j].second==-1)
                    {
                        primes[j].second=cnt;
                        cnt++;
                    }
                    ans.push_back(primes[j].second);
                    break;
                }
            }
        }
        cout<<cnt-1<<endl;
        for(auto x:ans)
            cout<<x<<" ";
        cout<<endl;
        ans.clear();
    }


}

