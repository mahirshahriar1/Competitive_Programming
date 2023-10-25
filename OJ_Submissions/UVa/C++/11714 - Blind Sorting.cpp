#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    while (cin >> n)
    {
        cout << n - 1 + (int)ceil(log2(n)) - 1 << endl;
        //n-1 to find maximum
        //to find 2nd maximum.. check the elements that were being compared with the maximum
        //there will be ceil(log2(n)) elements(height of tree) that were compared
        //so wee need ceil(log2(n))-1 to find maximum among those to get 2nd maximum
    }
    return 0;
}