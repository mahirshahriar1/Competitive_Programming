#include <bits/stdc++.h>
using namespace std;
#define long long int ll
 
int main()
{
    int t;
 
    cin>>t;
 
    while(t--)
    {
        int x,coun=0;
        cin>>x;
        string s;
        cin>>s;
        sort(s.begin(),s.end());
 
        for(int i=0; i<x; i++)
        {
            if(i==0)
                coun+=2;
            else
            {
                if(s[i]!=s[i-1])
                    coun+=2;
                else
                    coun++;
            }
 
        }
        cout<<coun<<endl;
    }
 
 
    return 0;
}
