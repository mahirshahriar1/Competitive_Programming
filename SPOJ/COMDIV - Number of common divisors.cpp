#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
typedef long long int ll;
using namespace std;

int NOD(int n) {
     int cnt = 0;
     for (int i = 1; i * i <= n; ++i) {
         if (n % i == 0) {
             ++cnt;
             if (n / i != i) {
                  ++cnt;
             }
         }
     }
     return cnt;
}

int GCD(int a, int b)
{
        if(b==0)
            return a;
        return GCD(b,a%b);
}


int main()
{
    fastio


    int n;
    cin>>n;

    while(n--)
    {
        int a,b;
        cin>>a>>b;
        int gcd=GCD(a,b);

        cout<<NOD(gcd)<<endl;


    }



    return 0;
}
