#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define oo 0x3f3f3f3f

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n, m, q, kas;
	kas = 0;
	while (cin >> n >> m >> q)
	{
		if (n == 0)
			break;
		int arr[101 + 1][101 + 1];

		memset(arr, oo, sizeof arr);
		
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			arr[x][y] = min (arr[x][y], z);
			arr[y][x] = min (arr[y][x], z);
		}

		// floyd warshall
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));

		if (kas)
			cout << endl;
		cout << "Case #" << ++kas << '\n';
		while (q--)
		{
			int x, y;
			cin >> x >> y;
			if (arr[x][y] == oo)
				cout << "no path" << '\n';
			else
				cout << arr[x][y] << '\n';
		}
	}

	return 0;
}