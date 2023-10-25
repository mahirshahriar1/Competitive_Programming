#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


int main()
{
    fastio;

    int t;
    cin>>t;

    while(t--)
    {
        int t2;cin>>t2;
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;

        map<string,int> m;
        for(int test=0;test<3;test++)
        {
            for(int i=0;i<t2;i++)
            {
                string s;
                cin>>s;
                if(test==0)
                    v1.push_back(s);
                else if(test==1)
                    v2.push_back(s);
                else
                    v3.push_back(s);
                m[s]++;
            }
        }
        int c1,c2,c3;
        c1=c2=c3=0;
        for(int i=0;i<t2;i++)
        {
            if(m[v1[i]]==1)
                c1+=3;
            else if(m[v1[i]]==2)
                c1++;
        }
         for(int i=0;i<t2;i++)
        {
            if(m[v2[i]]==1)
                c2+=3;
            else if(m[v2[i]]==2)
                c2++;
        }
         for(int i=0;i<t2;i++)
        {
            if(m[v3[i]]==1)
                c3+=3;
            else if(m[v3[i]]==2)
                c3++;
        }
        cout<<c1<<" "<<c2<<" "<<c3<<endl;


    }


    return 0;
}
