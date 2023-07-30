#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,t="heidi";

    getline(cin, s);

    int size=s.size(),flag=0,count=0,ind=0;

    for(int i=0;i<size;i++)
    {
        if(s[i]==t[ind])
        {
            ind++;
            count++;
        }
        if(count==5)
        {
            flag=1;
            break;
        }

    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}
