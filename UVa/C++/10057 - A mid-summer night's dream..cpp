#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL);

   int n;
   while (cin >> n)
   {
      vector<int> v(n);
      for (auto &i : v)
         cin >> i;
      sort(v.begin(), v.end());
      if (~n & 1)
      {
         int mid1 = v[n / 2];
         int mid2 = v[n / 2 - 1];
         int cnt = 0;
         for (auto i : v)
         {
            cnt += (i == mid1 || i == mid2);
         }
         cout << min(mid1, mid2) << " " << cnt << " " << mid1 - mid2 + 1 << endl;
      }
      else
      {
         int mid = v[n / 2];
         int cnt = 0;
         for (auto i : v)
         {
            cnt += (i == mid);
         }
         cout << mid << " " << cnt << " " << 1 << endl;
      }
   }
}
