#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;


    for(int i=0;i<10000;i++)
        s+=to_string(i);

    int x;
    cin>>x;

    cout<<s[x]<<endl;

    return 0;
}
