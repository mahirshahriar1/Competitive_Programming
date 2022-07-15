#include <bits/stdc++.h>
using namespace std;
#define long long int ll
 
int main()
{
    int t;
 
    cin>>t;
 
    while(t--)
    {
        int x;
        cin>>x;
 
 
        int arr[x];
 
        for(int i=0;i<x;i++)
            scanf("%d", &arr[i]);
 
        for(int i=0;i<x;i++)
        {
            int c;
            cin>>c;
            string s;
            cin>>s;
 
            for(int j=0;j<c;j++)
            {
                if(s[j]=='U')
                    arr[i]=((arr[i]-1)%10+10)%10;
                else
                     arr[i]=((arr[i]+1)%10+10)%10;
            }
        }
        for(int i=0;i<x;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
 
    }
 
 
    return 0;
}
