#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL);

   long long n;
   while (cin >> n, n != 0)
   {
      long long cnt = 0, ans = -1;
      n = abs(n);
      for (long long i = 2; i * i <= n and n != 1; i++)
      {
         while (n % i == 0)
         {
            n /= i;
            ans = i;
         }
         if (ans == i)
            cnt++;
      }
      if (n != 1 and ans != -1)
      {
         ans = n;
         cnt++;
      }

      cout << (cnt > 1 ? ans : -1) << endl;
   }
}
