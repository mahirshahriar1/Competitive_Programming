#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL);

   long long n;
   while (cin >> n, n != -1)
   {
      for (long long i = 2; i * i <= n; i++)
      {
         while (n % i == 0)
         {
            cout << "    " << i << endl;
            n /= i;
         }
      }
      if (n > 1)
         cout << "    " << n << endl;
      cout << endl;
   }
}
