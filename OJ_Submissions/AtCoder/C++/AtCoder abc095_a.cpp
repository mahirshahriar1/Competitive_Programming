#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);

    int x=0;

    for(int i=0;i<3;i++)
    {
        if(s[i]=='o')
            x++;
    }
    cout<<700+100*x<<endl;
}

