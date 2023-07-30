#include<bits/stdc++.h>
using namespace std;

int div_count(int n) {
     int cnt = 0;
     for (int i = 1; i * 1LL * i <= n; ++i) {
         if (n % i == 0) {
             if(i%2==0)
                cnt++;
             if (n / i != i) {
                 if((n/i)%2==0)
                   cnt++;
             }
         }
     }
     return cnt;
}



int main ()
{
    int n;
    long long int x;
    cin>>n;

    while(n--)
    {
        cin>>x;
        cout<<div_count(x)<<endl;
    }


    return 0;

}

