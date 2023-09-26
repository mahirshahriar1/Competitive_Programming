#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL);
   int tc;
   cin >> tc;
   for (int tt = 1; tt <= tc; tt++)
   {
      int n;
      cin >> n;
      vector<string> a(n), b(n);
      cin.ignore();
      for (int i = 0; i < n; i++)
      {
         string temp;
         getline(cin, temp);
         a[i] = temp;
      }
      for (int i = 0; i < n; i++)
      {
         string temp;
         getline(cin, temp);
         b[i] = temp;
      }
      int i = n - 1, j = n - 1;
      while (i >= 0 && j >= 0)
      {
         if (a[i] == b[j])
         {
            i--;
            j--;
         }
         else
         {
            i--;
         }
      }
      while (j >= 0)
      {
         cout << b[j] << endl;
         j--;
      }
      cout << endl;
   }
}