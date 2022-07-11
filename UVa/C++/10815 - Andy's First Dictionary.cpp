#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str,x;
    set<string> s;

    while(cin>>str)
    {
        x="";
        for(int i=0;i<str.size();i++)
        {
            if(isalpha(str[i]))
            {
                   x+=tolower(str[i]);
            }
            else if(x!="")
            {
                s.insert(x);
                x="";
            }
        }
        if(x!="")
         s.insert(x);
    }
    for(auto v: s)
        cout<<v<<endl;

    return 0;
}

/*#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str,x;
    set<string> s;

    while(cin>>str)
    {
        for(int i=0;i<str.size();i++)
        {
            if(isalpha(str[i]))
                str[i]=tolower(str[i]);
            else
                str[i]=' ';
        }
        stringstream a(str);
        while(a>>x)
            s.insert(x);
    }
    for(auto x: s)
        cout<<x<<endl;

    return 0;
}*/
