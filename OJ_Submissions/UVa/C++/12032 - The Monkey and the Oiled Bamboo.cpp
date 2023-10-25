#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'


bool check(int k, vector <int> &arr) {
    int cnt = 0;
    for (int i = 0; i + 1 < arr.size(); ++i) {
        if(arr[i + 1] - arr[i] == k) {
            ++cnt, --k;
        } else if (arr[i + 1] - arr[i] < k) {
            ++cnt;
        } else{
            return false;
        }
    }   
    return cnt + 1 == arr.size();    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {        
        int n;
        cin >> n;
        vector <int> arr(n + 1);
        arr[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
       
        cout << "Case " << ++tc << ": ";   

        ll l = 0, r = INT_MAX, ans = INT_MAX;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (check(mid, arr)) {
                ans = min(ans, mid);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        } 
        cout << ans << endl;   
    }

    return 0;
}