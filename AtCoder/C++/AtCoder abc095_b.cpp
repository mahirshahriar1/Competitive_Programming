#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,limit,y,count=0,sum=0;
    cin>>n>>limit;
    vector <int> arr;


    for(int i=0;i<n;i++)
    {
        cin>>y;
        arr.push_back(y);
    }
        sort(arr.begin(),arr.end());
   for(int i=0;i<n;i++)
        {
           if(sum+arr[i]<=limit)
           {
               sum+=arr[i];
                count++;
            }

        }


        while(sum+arr[0]<=limit)
        {
            sum=sum+arr[0];
            count++;
        }

        int i=1;
        while(1)
        {
            if(sum+arr[i]<=limit)
            {
                 sum+=arr[i];
                count++,i++;
            }
            if(i==n)
                i=1;
            if(sum+arr[i]>limit)
                break;

        }


        cout<<count<<endl;

}


