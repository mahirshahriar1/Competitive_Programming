#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b,c;

    getline(cin,a);

    getline(cin,b);

    getline(cin,c);

    a=a+b;

    int count=0;

    for(int i=0;i<c.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {

            if(c[i]==a[j])
            {
                count++;
                a[j]='0';
                break;
            }
        }
    }
    if(count==a.size()&&c.size()==count)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
