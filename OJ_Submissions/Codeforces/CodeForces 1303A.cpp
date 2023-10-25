#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin>>n;
    cin.ignore();

    while(n--)
    {
        getline(cin, s);

        int size=s.size(),count=0,flag=0;

        for(int i=size-1; i>=0; i--)
        {
            if(s[i]=='1')
                break;

            if(s[i]=='0')
                s.pop_back();
        }

        size=s.size();

        for(int i=0; i<size; i++)
        {
            if(!flag)
                if(s[i]=='1')
                    flag=1;

            if(flag)
                if(s[i]=='0')
                    count++;

        }

        cout<<count<<endl;

    }

    return 0;
}
