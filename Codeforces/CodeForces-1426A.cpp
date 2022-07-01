#include<bits/stdc++.h>
using namespace std;

int main ()
{
    double n,x,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        if(n==1||n==2)
            cout<<"1"<<endl;
        else
        {
            double y=((n-2)/x)+1;
            if((int)y==y)
                cout<<y<<endl;
            else
                cout<<int(y)+1<<endl;
        }
    }
    return 0;
}
