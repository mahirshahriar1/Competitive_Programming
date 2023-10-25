#include<bits/stdc++.h>
using namespace std;

int main ()
{
   int t,n,x;
   cin>>t;

   vector<int> arr;

   while(t--)
   {
       int count1=0;
       cin>>n;
       for(int i=0;i<n;i++)
       {
           cin>>x;
           arr.push_back(x);
       }
       sort(arr.begin(),arr.end());

       if(arr[0]==arr[n-1])
       {
            cout<<"0"<<endl;
            arr.clear();
            continue;
       }
       int c=0;
       for(int i=0;i<n;i++)
       {
           if(arr[i]==arr[0])
            c++;
        }
        cout<<n-c<<endl;

        arr.clear();
   }



    return 0;
}






