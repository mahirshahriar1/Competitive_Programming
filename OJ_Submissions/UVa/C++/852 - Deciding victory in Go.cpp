#include <bits/stdc++.h>
using namespace std;

char grid[10][10];

bool isValid(int i, int j)
{
    return i >= 0 && i < 9 && j >= 0 && j < 9;
}

bool b, w;
int cnt;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void dfs(int i, int j)
{
    if (grid[i][j] == '*')
        return;
    if (grid[i][j] == '.')
    {
        cnt++;
        grid[i][j] = '*';
    }
    if (grid[i][j] == 'X' || grid[i][j] == 'O')
    {
        b |= (grid[i][j] == 'X');
        w |= (grid[i][j] == 'O');
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (isValid(x, y))
            dfs(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int white = 0, black = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> grid[i][j];
                white += (grid[i][j] == 'O');
                black += (grid[i][j] == 'X');
            }
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == '.')
                {
                    b = 0, w = 0,
                    cnt = 0;
                    dfs(i, j);
                    if (b && !w)
                        black += cnt;
                    else if (w && !b)
                        white += cnt;
                    // cout<<i<<" "<<j<<" "<<b<<" "<<w<<" "<<cnt<<"\n";
                }
            }
        }
        cout << "Black " << black << " White " << white << "\n";
    }
}