#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    getline(cin, s);

    int count=1;

    for(int i=0;i<s.size();i++)
         if(s[i]>='A'&&s[i]<='Z')
            count++;

    cout<<count<<endl;


    return 0;
}
