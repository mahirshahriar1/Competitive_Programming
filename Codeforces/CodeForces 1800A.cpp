#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string toLower(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
    return s;
}

int main()
{
    ll test;
    cin >> test;

    for (ll testt = 1; testt <= test; testt++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = toLower(s);
        string out = "";
        for (int i = 0; i < n; i++)
        {
            out += s[i];
            while (i < n - 1 && s[i] == s[i + 1])
                i++;
        }
     
        if (out == "meow")
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
