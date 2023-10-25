#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main ()
{
   int n,a,b;

   cin>>n>>a>>b;

   int ans=(((a+b)%n)+n)%n;
   if(ans==0)
        cout<<n<<endl;
    else
        cout<<ans<<endl;


    return 0;

}

