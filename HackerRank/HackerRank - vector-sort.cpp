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

    for(int i=0;i<x;i++)
        cout<<a[i]<<" ";

    cout<<endl;

    return 0;
}
