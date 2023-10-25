#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

int main()
{
	fastio
#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int test;
	cin >> test;
	while (test--)
	{
		string s;
		cin >> s;
		int n = s.size();
		int front[n + 1], back[n + 1];
		memset(front, 0, sizeof(front));
		memset(back, 0, sizeof(back));

		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				front[i] = s[i] - '0';
			}
			else
			{
				front[i] = s[i] - '0' + front[i - 1];
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			back[i] = s[i] - '0' + back[i + 1];
		}
		int ans = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			ans = min(ans, i + 1 - front[i] + back[i + 1]);
			ans = min(ans, front[i] + (n - i - 1) - back[i + 1]);
		}
		cout << ans << endl;
	}

	return 0;
}
