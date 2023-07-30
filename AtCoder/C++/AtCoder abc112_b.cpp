#include<bits/stdc++.h>
using namespace std;

int main ()
{
   int N,T,x;
   vector<int> c;
   vector<int> t;
   cin>>N>>T;

   for(int i=0;i<N;i++)
   {
       cin>>x;
       c.push_back(x);
       cin>>x;
       t.push_back(x);
   }
   int mini=10000,flag=0;

   for(int i=0;i<N;i++)
   {
       //cout<<c[i]<<" "<<t[i]<<endl;
       if(c[i]<mini&&t[i]<=T)
       {
          mini=c[i];
          flag=1;
       }

   }
   if(flag)
    cout<<mini<<endl;
   else
    cout<<"TLE"<<endl;



    return 0;
}


