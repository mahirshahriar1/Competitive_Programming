#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b,c;

    getline(cin,a);
    b="";

    for(int i=0; i<a.size(); i++)
    {
        if(a[i]>='a'&&a[i]<='z')
        {
            if(a[i-1]=='<')
            {
                cout<<b<<"<"<<a[i]<<">"<<endl;
                b+="  ";
            }

            else
            {
                b.erase(b.size()-2,b.size());
                cout<<b<<"</"<<a[i]<<">"<<endl;
            }

        }
    }


    return 0;
}

