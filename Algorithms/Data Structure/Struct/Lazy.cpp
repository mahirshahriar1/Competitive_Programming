template <class T>
struct segment_tree
{
    int n;
    vector<T> stree, lzadd, lzset;
    function<T(const T &, const T &)> merge;
    T identity = T();
    T add_identity = T();
    T set_identity = T();
    segment_tree(int n, function<T(const T &, const T &)> merge, T identity, T add_identity, T set_identity) : n(n), merge(merge), identity(identity), add_identity(add_identity), set_identity(set_identity)
    {
        stree.resize(4 * n + 5);
        lzadd.resize(4 * n + 5, add_identity);
        lzset.resize(4 * n + 5, set_identity);
    }
    void build(const vector<T> &arr, int node, int b, int e)
    {
        if (b == e)
        {
            stree[node] = arr[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(arr, 2 * node, b, mid);
        build(arr, 2 * node + 1, mid + 1, e);
        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
    }
    segment_tree(const vector<T> &arr, function<T(const T &, const T &)> merge, T identity, T add_identity, T set_identity) : n(arr.size()), merge(merge), identity(identity), add_identity(add_identity), set_identity(set_identity)
    {
        stree.resize(4 * n + 5);
        lzadd.resize(4 * n + 5, add_identity);
        lzset.resize(4 * n + 5, set_identity);
        build(arr, 1, 0, n - 1);
    }

    void propagate(int node, int b, int e)
    {
        if (lzset[node] != set_identity)
        {
            lzadd[node] = add_identity;
            stree[node] = lzset[node] * (e - b + 1);
            if (b != e)
            {
                lzset[2 * node] = lzset[node];
                lzset[2 * node + 1] = lzset[node];
            }
            lzset[node] = set_identity;
        }
        else
        {
            if (lzadd[node] == add_identity)
                return;
            stree[node] += lzadd[node] * (e - b + 1); 
            // for min
            // stree[node] += lzadd[node];
            if (b != e)
            {
                if (lzset[2 * node] == set_identity)
                {
                    lzadd[2 * node] += lzadd[node];
                }
                else
                {
                    lzset[2 * node] += lzadd[node];
                    lzadd[2 * node] = 0;
                }
                if (lzset[2 * node + 1] == set_identity)
                {
                    lzadd[2 * node + 1] += lzadd[node];
                }
                else
                {
                    lzset[2 * node + 1] += lzadd[node];
                    lzadd[2 * node + 1] = 0;
                }
            }
            lzadd[node] = add_identity;
        }
    }

    void update(int node, int b, int e, int l, int r, T val)
    {
        propagate(node, b, e);
        if (l > e or r < b)
            return;
        if (l <= b and r >= e)
        {
            lzadd[node] += val; // apply to lazy
            propagate(node, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        update(2 * node, b, mid, l, r, val);
        update(2 * node + 1, mid + 1, e, l, r, val);

        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
        return;
    }
    void update(int l, int r, T val)
    {
        update(1, 0, n - 1, l, r, val);
    }

    void set(int node, int b, int e, int l, int r, T val)
    {
        propagate(node, b, e);
        if (l > e or r < b)
            return;
        if (l <= b and r >= e)
        {
            lzset[node] = val; // apply to lazy
            propagate(node, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        set(2 * node, b, mid, l, r, val);
        set(2 * node + 1, mid + 1, e, l, r, val);

        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
        return;
    }
    void set(int l, int r, T val)
    {
        set(1, 0, n - 1, l, r, val);
    }

    T query(int node, int b, int e, int l, int r)
    {
        propagate(node, b, e);
        if (l > e or r < b)
            return identity;
        if (l <= b and r >= e)
            return stree[node];
        int mid = (b + e) >> 1;
        T c1 = query(2 * node, b, mid, l, r);
        T c2 = query(2 * node + 1, mid + 1, e, l, r);
        return merge(c1, c2);
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};