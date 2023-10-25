#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int kas;
vector<vector<char>> grid(100, vector<char>(100));

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL);
   int tc;
   cin >> tc;
   for (int tt = 1; tt <= tc; tt++)
   {
      int n;
      cin >> n;

      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            cin >> grid[i][j];

      auto isValid = [&](int i, int j, int n, char c)
      {
         if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == c)
            return true;
         return false;
      };

      auto check = [&](int i, int j, int n, char c)
      {
         for (int k = 0; k < 4; k++)
         {
            int x = i + dx[k];
            int y = j + dy[k];
            if (isValid(x, y, n, c))
               return false;
         }
         return true;
      };

      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (grid[i][j] != '.')
               continue;
            for (char c = 'A'; c <= 'Z'; c++)
            {
               if (check(i, j, n, c))
               {
                  grid[i][j] = c;
                  break;
               }
            }
         }
      }
      cout << "Case " << tt << ":" << endl;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
            cout << grid[i][j];
         cout << endl;
      }
   }
}