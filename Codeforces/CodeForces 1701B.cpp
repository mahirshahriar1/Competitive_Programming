#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int t,x,d;
    cin>>t;
    while(t--)
    {
        cin>>x;
 
        cout<<"2"<<endl;
 
        for(int i=1;i<=x;i+=2)
        {
            for(int j=i;j<=x;j*=2)
                cout<<j<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}
