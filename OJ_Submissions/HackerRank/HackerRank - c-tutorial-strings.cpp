#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;

    getline(cin,a);
    getline(cin,b);

    cout<<a.size()<<" ";
    cout<<b.size()<<endl;

    cout<<a+b<<endl;

    char a1=a[0];
    a[0]=b[0];
    b[0]=a1;

    cout<<a<<" "<<b<<endl;

    return 0;
}
