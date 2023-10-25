
#include <bits/stdc++.h>
using namespace std;
#define long long int ll
 
int main()
{
 
    int t;
    string s;
    cin>>t;
 
    while(t--)
    {
        cin>>s;
        string x="";
 
        for(int i=0;i<3;i++)
        {
            x+=tolower(s[i]);
        }
        if(x=="yes")
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
 
 
 
    return 0;
}
