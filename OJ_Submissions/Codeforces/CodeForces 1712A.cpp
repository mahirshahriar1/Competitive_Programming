//https://codeforces.com/contest/1712/problem/A

#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

int main()
{
    fastio;
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int n, k ;
        cin>>n>>k;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int cnt=0;

        for(int i=1; i<=k; i++)
        {
            bool flag=false;
            for(int j=0;j<k;j++)
            {
                if(arr[j]==i)
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
                cnt++;
        }

        cout<<cnt<<endl;
    }
    return 0;
}


/*

int test_case;
	cin >> test_case;
	while (test_case--)
	{
		int n, k , count(0); cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		for (int i = k; i < n; ++i)
		{
			if (arr[i] <= k) count++;
		}
		cout << count << endl;
	}
  
  */
