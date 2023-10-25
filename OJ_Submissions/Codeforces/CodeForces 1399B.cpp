#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t,n,input,min1,min2;

    cin>>t;
    while(t--)
    {
        cin>>n;
        vector <long long> arr1;
        vector <long long> arr2;
        for(int i=0;i<n;i++)
        {
            cin>>input;
            arr1.push_back(input);
        }
        for(int i=0;i<n;i++)
        {
            cin>>input;
            arr2.push_back(input);
        }
        min1=arr1[0];
        min2=arr2[0];
        for(int i=0;i<n;i++)
        {
            if(arr1[i]<=min1)
                min1=arr1[i];
             if(arr2[i]<=min2)
                min2=arr2[i];
        }
        long long sum1,sum2,sumfinal;
        sum1=sum2=sumfinal=0;
          for(int i=0;i<n;i++)
         {
             if(arr1[i]>=min1||arr2[i]>=min2)
             {
                 sum1=arr1[i]-min1;
                sum2=arr2[i]-min2;
             }
             if(sum1>sum2)
                sumfinal+=sum1;
            else
                sumfinal+=sum2;

         }
         cout<<sumfinal<<endl;



    }
}



