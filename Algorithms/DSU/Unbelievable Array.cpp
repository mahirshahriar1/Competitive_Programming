// https://toph.co/p/unbelievable-array

//You will be given an array A of n integers and q operations. There are two types of operations:

// 1 x y, for this operation, you should replace all the occurrences of element x in the array with y
// 2 idx, output the value A[idx]

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

struct DSU
{
    vector<int> rep;
    int cc;
    DSU(int sz)
    {
        rep = vector<int>(sz, -1);
        cc = sz - 1;
    }

    int get(int x) { return rep[x] < 0 ? x : rep[x] = get(rep[x]); }
    bool same_set(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -rep[get(x)]; }

    bool unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return false;
        if (rep[x] > rep[y])
            swap(x, y);
        rep[x] += rep[y];
        cc--;
        rep[y] = x;
        return true;
    }
};

const int N = 100000 + 5;
vector<int> g[N];

void run_case(const int &tc)
{
    cout << "Case " << tc << ":\n";
    int n, q;
    cin >> n >> q;
    DSU dsu(N);
    for (int i = 0; i < N; ++i)
        g[i].clear();
    vector<int> ind(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        // if there is an existing element merge the indexes
        if (g[x].size())
            dsu.unite(i, g[x].back());
        g[x].push_back(i);
        // set ind[root of the set] = x
        // we can make queries like ind[dsu.get(any index of the set)] and get the answer
        ind[dsu.get(i)] = x;
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            if (x == y)
                continue;

            // merge the smaller set into the larger set
            if (g[y].size() < g[x].size())
                swap(g[y], g[x]);

            for (auto &i : g[x])
            {
                // check size otherwise runtime
                if (g[y].size())
                    dsu.unite(i, g[y].back());
                g[y].push_back(i);
            }
            // clear the smaller set
            g[x].clear();
            // if the set is not empty set the ind[root of the set] = y
            if (g[y].size())
                ind[dsu.get(g[y].back())] = y;
        }
        else
        {
            int x;
            cin >> x;
            cout << ind[dsu.get(x)] << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        run_case(tc);
    }

    return 0;
}
