#include <bits/stdc++.h>

using namespace std;

int main()
{
    string id;

    while (1)
    {
        cin >> id;
        if(id[0]=='#')
            break;
        if(next_permutation(id.begin(),id.end()))
            cout<<id<<endl;
        else
            cout<<"No Successor"<<endl;
    }
}
