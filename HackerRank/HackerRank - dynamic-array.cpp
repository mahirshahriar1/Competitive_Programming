#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,idx,x,y,q,t;
    cin>>n>>q;

    vector<vector<long>> arr(n);

    long lastAnswer=0;

    while(q--)
    {
        cin>>t>>x>>y;

        if(t==1)
        {
            idx=((x^lastAnswer)%n);
            arr[idx].push_back(y);
        }
        else if(t==2)
        {
            idx=((x^lastAnswer)%n);
            lastAnswer=arr[idx][y%arr[idx].size()];
            cout<<lastAnswer<<endl;
        }
    }


    return 0;
}



