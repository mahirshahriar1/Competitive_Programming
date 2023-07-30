#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--)
    {
        int x;
        cin>>x;
        map <string,int> m;
        while(x--)
        {
            string s,in="";
            cin>>s;
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]=='-')
                    continue;
                else if(s[i]=='A'||s[i]=='B'||s[i]=='C')
                    in+='2';
                else if(s[i]=='D'||s[i]=='E'||s[i]=='F')
                    in+='3';
                else if(s[i]=='G'||s[i]=='H'||s[i]=='I')
                    in+='4';
                else if(s[i]=='J'||s[i]=='K'||s[i]=='L')
                    in+='5';
                else if(s[i]=='M'||s[i]=='N'||s[i]=='O')
                    in+='6';
                else if(s[i]=='P'||s[i]=='R'||s[i]=='S')
                    in+='7';
                else if(s[i]=='T'||s[i]=='U'||s[i]=='V')
                    in+='8';
                else if(s[i]=='W'||s[i]=='X'||s[i]=='Y')
                    in+='9';
                else if(s[i]>='0'&&s[i]<='9')
                    in+=s[i];
            }
            m[in]++;
        }
        int flag=1;
        for(auto x:m)
        {
            if(x.second>1)
            {
                flag=0;
                for(int i=0; i<3; i++)
                    cout<<x.first[i];
                cout<<"-";
                for(int i=3; i<7; i++)
                    cout<<x.first[i];
                cout<<" "<<x.second<<endl;
            }
        }
        if(flag)
            cout<<"No duplicates."<<endl;
        if(t>=1)
            cout<<endl;
    }


    return 0;
}
