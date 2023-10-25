#include<bits/stdc++.h>
using namespace std;


int main ()
{
    long long int b,sum=0,i;
    cin>>b;

    vector <long long int> arr;

    for(i=1;sum<b;i++)
    {
        sum=sum+i;
    }
    cout<<i-1<<endl;



    return 0;

}

