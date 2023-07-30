#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a;

    int n,t,x,y,z;

    cin>>n;
    a.push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>t;
         a.push_back(t);
    }
    a.push_back(0);
    cin>>z;


    while(z--)
    {
        cin>>x>>y;
        a[x-1]+=y-1;
        a[x+1]+=a[x]-y;
        a[x]=0;
    }

    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;

    return 0;
}


