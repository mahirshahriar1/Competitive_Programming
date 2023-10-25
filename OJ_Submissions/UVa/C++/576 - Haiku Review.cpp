#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;

bool vowel(char c)
{
    return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y');
}

int check(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (vowel(s[i]))
        {
            cnt++;
            if (i and vowel(s[i - 1]))
            {
                cnt--;
            }
        }
    }
    return cnt;
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    while (getline(cin, s))
    {
        if (s == "e/o/i")
            break;

        vector<string> v;
        string tmp = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '/')
            {
                v.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += s[i];
        }
        v.push_back(tmp);

        bool flag = true;
        int counts[] = {5, 7, 5};
        int ind = -1;

        for (int i = 0; i < v.size(); i++)
        {
            ind++;
            int cnt = 0;
            tmp = "";
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j] == ' ')
                {
                    cnt += check(tmp);
                    // cout<<tmp<<' '<<check(tmp)<<endl;
                    tmp = "";
                }
                else
                    tmp += v[i][j];
            }
            if (tmp.size())
            {
                cnt += check(tmp);
                // cout<<tmp<<' '<<check(tmp)<<endl;
            }
            if (counts[ind] != cnt)
            {
                cout << i + 1 << endl;
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Y" << endl;
    }
}
