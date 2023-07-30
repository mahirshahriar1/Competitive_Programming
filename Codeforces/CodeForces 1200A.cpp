#include <bits/stdc++.h>

using namespace std;

int main()
{
   int x;

   cin>>x;
    cin.ignore();
   string s,t;
   getline(cin,s);

   for(int i=0;i<10;i++)
        t.push_back('0');

  int j, k;
   for(int i=0;i<x;i++)
   {
       j=0,k=9;
       if(s[i]=='L')
       {
           while(t[j]!='0')
                j++;

            t[j]='1';
        }

        else if(s[i]=='R')
        {
             while(t[k]!='0')
                k--;
            t[k]='1';          
        }

        else if(s[i]>='0'&&s[i]<='9')
        {
            int index=(int)s[i]-'0';
            t.replace(index,1,"0");

        }

  }
  cout<<t<<endl;

    return 0;
}
