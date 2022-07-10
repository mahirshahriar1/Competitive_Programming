#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
   int t, arr[2][2];
 
   cin>>t;
 
   while(t--)
   {
       int sum=0;
      for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
        if(sum==0)
            cout<<"0"<<endl;
        else if(sum==1||sum==2||sum==3)
            cout<<"1"<<endl;
        else
            cout<<"2"<<endl;
 
   }
 
 
    return 0;
}
 
