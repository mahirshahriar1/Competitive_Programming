#include <bits/stdc++.h>

using namespace std;



int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);

    int count=0;

    for (int i=a.size()-1, j=b.size()-1; i>=0, j>=0;i--,j--)
    {
        if(a[i]==b[j])
            count++;

        else
            break;
    }

    cout<<a.size()-count+b.size()-count<<endl;

    return 0;
}
