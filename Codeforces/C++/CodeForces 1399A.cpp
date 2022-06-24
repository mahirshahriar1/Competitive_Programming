#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,x,input;
    cin>>t;

    while(t--)
    {
        vector <int> arr;
        cin>>x;
        for(int i=0;i<x;i++)
        {
            cin>>input;
            arr.push_back(input);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<x;i++)
        {
            for(int j=i+1;j<x;j++)
            {
                if(abs(arr[i]-arr[j])<=1)
                {
                    if(arr[i]<=arr[j])
                        arr[i]=0;
                    else
                        arr[j]=0;
                }
            }
        }
        int count=0,flag=1;
        for(int i=0;i<x;i++)
        {
            if(arr[i]!=0)
                count++;
            if(count>1)
            {
                cout<<"NO"<<endl;
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;


    }

}



