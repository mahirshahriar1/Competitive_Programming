#include <bits/stdc++.h>
using namespace std;

int n, m, kas;
bool isValid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}

const int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};

int main()
{
    bool flag = false;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        if (flag)
            cout << "\n";
        flag = true;

        cout << "Field #" << ++kas << ":\n";
        char arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0;
                if (arr[i][j] == '*')
                    cout << arr[i][j];
                else
                {
                    for (int k = 0; k < 8; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (isValid(x, y) && arr[x][y] == '*')
                            cnt++;
                    }
                    cout << cnt;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}