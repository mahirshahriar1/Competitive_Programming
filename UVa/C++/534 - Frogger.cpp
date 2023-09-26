//Used Floyd Warshall minimax algorithm
//we can use kruskal's algorithm as well ~ need to do that

#include <bits/stdc++.h>
using namespace std;

struct point
{
	int x, y;
};

double calc(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
	int n;
	int kas = 0;
	while (cin >> n, n!=0)
	{	
		kas++;
		vector<point> v(n);
		for (auto &[x, y] : v)
			cin >> x >> y;

		double arr[210][210];
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				arr[i][j] = arr[j][i] = calc(v[i], v[j]);
			}
		}
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));
				}
			}
		}
		cout << "Scenario #" << kas << '\n';
		cout << "Frog Distance = " << fixed << setprecision(3) << arr[0][1] << "\n\n";
	}
}