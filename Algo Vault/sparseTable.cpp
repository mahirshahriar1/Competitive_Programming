
template<typename T>
class SparseTable {
private:
    vector<vector<int>> st; // Sparse Table
    vector<int> logs;
    vector<T> *arr;
    int N, K; // Size of the array and the sparse table
    function<bool(const T&, const T&)> compare; // Comparison function
 
public:
    SparseTable(vector<T>& input, function<bool(const T&, const T&)> cmp) : compare(cmp) {
        arr = &input;
        N = input.size();
        K = log2(N) + 1;
        st.assign(N, vector<int>(K));
 
        // Initialize base case (k = 0)
        for (int i = 0; i < N; ++i)
            st[i][0] = i;
 
        // Precompute all other values
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= N; ++i) {
                int x = st[i][j - 1];
                int y = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = compare((*arr)[x], (*arr)[y]) ? x : y;
            }
        }
 
        logs.resize(N + 1);
        logs[1] = 0;
        for (int i = 2; i <= N; ++i)
            logs[i] = logs[i / 2] + 1;
    }
 
    int query(int left, int right) {
        int j = logs[right - left + 1];
        int x = st[left][j];
        int y = st[right - (1 << j) + 1][j];
        return compare((*arr)[x], (*arr)[y]) ? x : y;
    }
};
 
 // ------------------------------


const int N = 2e5 + 5, LG = 18;
int64_t st[N][LG], lgs[N];

void sparse_table(vector<int> &a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        st[i][0] = a[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        lgs[i] = __lg(i);
    }

    for (int j = 1; j < LG; ++j)
    {
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
        {
            st[i][j] = (st[i][j - 1] + st[i + (1 << (j - 1))][j - 1]);
            // st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int l, int r)
{
    int j = lgs[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int range_and(int l, int r)
{
    int res = st[l][0];
    for (int j = LG - 1; j >= 0; --j)
    {
        if ((1 << j) <= r - l + 1)
        {
            res &= st[l][j];
            l += (1 << j);
        }
    }
    return res;
}
// find the first index to right which has value = val
auto find_right = [&](int ind, int val) -> int
{
    if (rmx(ind, n - 1) < val)
        return -1;
    int low = ind, high = n - 1, ret = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int q = rmx(ind, mid);
        if (q >= val)
        {
            ret = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (ret != -1 and rmx(ind, ret) != val)
        return -1;
    return ret;
};

// find the  first index to left which has value = val
auto find_left = [&](int ind, int val) -> int
{
    if (rmx(0, ind) < val)
        return -1;
    int low = 0, high = ind, ret = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int q = rmx(mid, ind);
        if (q >= val)
        {
            ret = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (ret != -1 and rmx(ret, ind) != val)
        return -1;
    return ret;
};

// number of elements in range [l, r] which are >= k with start index l
auto get_l = [&](int l, int r, int k)
{
    if (l < 0 || r >= n)
        return 0;
    int L = 1, R = r - l + 1;
    int ans = 0;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if ((r - mid + 1) >= 0 && rmq(r - mid + 1, r) >= k)
        {
            L = mid + 1;
            ans = mid;
        }
        else
            R = mid - 1;
    }
    return ans;
};
// number of elements in range [l, r] which are >= k with start index r
auto get_r = [&](int l, int r, int k)
{
    if (l < 0 || r >= n)
        return 0;
    int L = 1, R = r - l + 1;
    int ans = 0;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if ((l + mid - 1) < n && rmq(l, l + mid - 1) >= k)
        {
            L = mid + 1;
            ans = mid;
        }
        else
            R = mid - 1;
    }
    return ans;
};