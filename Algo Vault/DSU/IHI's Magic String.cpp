//https://codeforces.com/gym/103736/problem/J

// IHI has recently acquired a magic power that can perform the following operations on strings: 
// 1.puts a character at the end of a string. 
// 2.deletes a character at the end of a string (does not operate if the string is empty). 
// 3.replaces all current character x in the string to characters y . 
// All characters are lowercase. 
// Now IHI has a string that starts empty, he wants to know what the final string is after q operations.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> st[26];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            char c;
            cin >> c;
            st[c - 'a'].insert(++cnt);
        }
        else if (type == 2) {
            if (cnt) {
                for (int i = 0; i < 26; ++i) st[i].erase(cnt);                
                --cnt;
            }
        }
        else {
            char x, y;
            cin >> x >> y;
            if (x ^ y) {
                int from = x - 'a';
                int to = y - 'a';
                if (st[from].size() > st[to].size()) {
                    swap(st[from], st[to]);                
                }
                for (auto it : st[from]) {
                    st[to].insert(it);                
                }
                st[from].clear();
            }
        }
    }

    if (!cnt) {
        cout << "The final string is empty" << endl;
        return 0;
    }
    string str = string(cnt, 'a');
    for (int i = 0; i < 26; ++i)
        for (int j : st[i])
            str[j - 1] = i + 'a';
        
    
    cout << str << endl;
}
