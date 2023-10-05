#include <bits/stdc++.h>
using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

int myrand(int mod) {
    return mt()%mod;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n = myrand(20);
    int w = myrand(100);
    cout << w <<' '<< n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rand() % 100 + 1 << ' ' << myrand(100) + 1 << endl;
    }

    return 0;
}
