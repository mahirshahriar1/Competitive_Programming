#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,t=1;
    cin>>n;
    cin.ignore();

    string s;
    getline(cin,s);

    for(int i=1;i<s.size();i++) // loop 0 theke shuru korle substr ta mach korbei
    {
        if(s.substr(0,i)==s.substr(i,i))// 0 theke i index porjonto and i index theke i index length porjonto
        {
            //cout<<s.substr(0,i)<<endl;
                t=i;
        }
    }

    cout<<n-t+1<<endl;  //+1 because copy korte ekta step


    return 0;
}



