#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a;

    int x,num;
    cin>>x;

    for(int i=0;i<x;i++)
    {
        cin>>num;
        a.push_back(num);
    }


   sort(a.begin(),a.end());

   int mark=a[0],flag=1;

    for(int i=0;i<x;i++)
        {
            if(a[i]!=a[0])
            {
                   cout<<a[i]<<endl;
                   flag=0;
                   break;
            }
        }

    if(flag)
        cout<<"NO"<<endl;

    return 0;
}

