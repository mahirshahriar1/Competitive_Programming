#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,t,ans;

    getline(cin,s);
    getline(cin,t);

    int j=0,k=0;
    for(int i=0;i<(s.size()+t.size());i++)
    {
        if(i%2)
            ans+=t[j++];
        else
            ans+=s[k++];
    }


    cout<<ans<<endl;


    return 0;
}
