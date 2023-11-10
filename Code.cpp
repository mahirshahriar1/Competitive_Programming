int64_t ceil_log2(int64_t n)
{
    auto ispower2 = [](int64_t n)
    {
        return n && !(n & (n - 1));
    };
    int64_t cnt = 0, temp = n;
    while (temp >>= 1)
        cnt++;
    return cnt + !ispower2(n);
}
int log(ll x) { return __builtin_clzll(1ll) - __builtin_clzll(x); }

// EPS
const double eps = 1e-9;
bool isEqual(double a, double b) { return abs(a - b) <= eps; }
bool isSmaller(double a, double b) { return a + eps < b; } // a < b
bool isGreater(double a, double b) { return a > b + eps; } // a > b

vector<bool> isprime;
vector<ll> primes;

void sieve(ll n)
{
    isprime.assign(n + 1, true);
    isprime[0] = isprime[1] = false;

    for (ll i = 2; i * i <= n; i++)
    {
        if (!isprime[i])
            continue;
        for (ll j = i * i; j <= n; j += i)
            isprime[j] = false;
    }
    for (ll i = 2; i <= n; i++)
        if (isprime[i])
            primes.push_back(i);
}

vector<int> NOD; // number of divisors

void sieve_NOD(int n)
{
    NOD.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            ++NOD[j];
        }
    }
} // O(n * log n)

vector<int> SOD;
void sieve_SOD(int n)
{

    SOD.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
            SOD[j] += i;
    }

} // O(n * log n)

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
} // O(log min(a,b))

int lcm(int a, int b)
{
    return (a / GCD(a, b)) * b;
}

int modulo(string num, int mod)
{
    int res = 0; // check constraints to know if long long is needed

    int i = 0;
    if (num[0] == '-')
        i = 1; // if negative number then start from 1

    for (; i < num.size(); i++) /// for (int i = (num.front() == '-' ? 1 : 0); i < num.size(); i++)
    {
        int d = num[i] - '0';
        res = (res * 10) + d;
        res %= mod;
    }

    if (num[0] == '-')
    {
        res = ((-res) % mod + mod) % mod;
    }

    return res;
}

ll binExpRecur(int a, int b) // power
{
    if (b == 0)
        return 1;
    ll res = binExpRecur(a, b / 2);
    if (b & 1)
        return a * res * res;
    else
        return res * res;
}
ll binExpRecurMod(ll a, ll b, ll m) // pow function
{
    if (b == 0)
        return 1;
    ll res = binExpRecurMod(a, b / 2, m);
    if (b & 1)
        return a % m * res % m * res % m;
    else
        return res % m * res % m;
}

// O(sqrt (n))
vector<int> divisors(int n)
{
    vector<int> div;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            if (n / i != i)
            {
                div.push_back(n / i);
            }
        }
    }
    sort(div.begin(), div.end());
    return div;
}

// more efficient
vector<int> divisors(int n)
{
    vector<int> div;
    vector<int> buf; // buffer (temp. storage)
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            buf.push_back(n / i);
        }
    }
    int from = buf.front() == div.back() ? 1 : 0;
    for (int i = buf.size() - 1; i >= from; --i)
    {
        div.push_back(buf[i]);
    }
    return div;
} // O(sqrt (n))

int NOD(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ++cnt;
            if (n / i != i)
            {
                ++cnt;
            }
        }
    }
    return cnt;
} // O(sqrt (n))

int SOD(int n)
{
    int sum = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            sum += i;
            if (n / i != i)
            {
                sum += n / i;
                ;
            }
        }
    }
    return sum;
}

bool is_prime(int n)
{
    if (n == 1)
        return false; //////////
    for (int i = 2; i * 1ll * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

long long int rev(long long int y)
{
    long long int reversed_number = 0;
    while (y)
    {
        reversed_number = reversed_number * 10 + y % 10;
        y /= 10;
    }
    return reversed_number;
}

vector<int> pfactors(int n)
{
    vector<int> result;
    for (int p = 2; p * p <= n; p++)
    {
        while (n % p == 0)
        {
            n /= p;
            result.push_back(p);
        }
    }
    if (n > 1)
        result.push_back(n);
    return result;
}

vector<int> pfactors_v2(int n) // initialize sieve for this
{
    vector<int> result;
    for (ll p : primes)
    {
        if (p * p > n)
            break;
        while (n % p == 0)
        {
            n /= p;
            result.push_back(p);
        }
    }
    if (n > 1)
        result.push_back(n);

    return result;
}

vector<pair<ll, ll>> pfactors_pair(ll n) // prime factor pair
{
    vector<pair<ll, ll>> result;
    for (ll p = 2; p * p <= n; p++)
    {
        ll cnt = 0;
        if (n % p)
            continue;
        while (n % p == 0)
        {
            n /= p;
            ++cnt;
        }
        result.push_back({p, cnt});
    }
    if (n > 1)
        result.push_back({n, 1});
    return result;
}
-- -- -- -- -- -- -- -map<int, int> mp;
for (int i = 2; i * i <= n; i++)
{
    while (n % i == 0)
    {
        mp[i]++;
        n /= i;
    }
}
if (n > 1)
    mp[n]++;
-- -- -- -- -- -- -- --vector<pair<ll, ll>> pfactors_pair(ll n) // initialize sieve for this
{
    vector<pair<ll, ll>> result;
    for (ll p : primes)
    {
        if (p * p > n)
            break;
        if (n % p)
            continue;
        ll exp = 0;
        while (n % p == 0)
        {
            n /= p;
            exp++;
        }
        result.push_back({p, exp});
    }
    if (n > 1)
        result.push_back({n, 1});

    return result;
}

int count_pfactor(int n, int limit) // limit prime.size()
{
    int size = sqrt(n), count(0);
    for (int i = 0; priems[i] <= size && i < limit; i++)
    {
        bool sign = false;
        while (n % primes[i] == 0)
        {
            n /= primes[i];
            sign = true;
        }
        size = sqrt(n);
        if (sign)
            count++;
    }
    if (n > 1)
        count++;
    return count;
}

vector<int> p_factors; // forthright
void factorize(int n)
{
    // primes[i] * 1LL * primes[i] <= num
    int sqrtn = sqrt(n);
    for (int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
    {
        // if ( sieve[n] == 0 ) break; /*Checks if n is prime or not*/
        if (n % prime[i] == 0)
        {
            while (n % prime[i] == 0)
            {
                n /= prime[i];
                factors.push_back(prime[i]);
            }
            sqrtn = sqrt(n);
        }
    }
    if (n != 1)
    {
        factors.push_back(n);
    }
} // forthright

int SOD_pfactor(int n)
{
    int res = 1;
    for (int p = 2; p * p <= n; p++)
    {
        int tempSum = 1;
        int x = 1;
        while (n % p == 0)
        {
            n /= p;
            x *= p;
            tempSum += x;
        }
        res *= tempSum;
    }
    if (n > 1)
        res *= (n + 1);
    return res;
}

int SOD_pfactor_v2(int n)
{
    int res = 1;
    int sqrtn = sqrt(n);
    for (int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
    {
        if (n % prime[i] == 0)
        {
            int tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while (n % prime[i] == 0)
            {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt(n);
            res *= tempSum;
        }
    }
    if (n != 1)
    {
        res *= (n + 1); // Need to multiply (p^0+p^1)
    }
    return res;
}

int NOD_pfactor(int n)
{
    int sqrtn = sqrt(n);
    int res = 1;
    for (int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
    {
        if (n % prime[i] == 0)
        {
            int p = 0; // Counter for power of prime
            while (n % prime[i] == 0)
            {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt(n);
            p++;      // Increase it by one at end
            res *= p; // Multiply with answer
        }
    }
    if (n != 1)
    {
        res *= 2; // Remaining prime has power p^1. So multiply with 2/
    }
    return res;
}

ll pfactors_NOD(ll n)
{
    ll result = 1;
    ll sqrtn = sqrt(n);
    for (int p = 2; p <= sqrtn; p++)
    {
        ll cnt = 0;
        while (n % p == 0)
        {
            n /= p;
            cnt++;
        }
        cnt++;
        result *= cnt;
        sqrtn = sqrt(n);
    }
    if (n > 1)
        result *= 2;
    return result;
}

ll trailingZeroes(ll n)
{
    ll ans = 0;
    ll p = 5;
    while ((n / p) > 0)
    {
        ans += (n / p);
        n /= 5;
    }

    return ans;
} // min(2,5) pair

// To find the power of a prime p in
// factorial N
ll frequency(ll n, ll p) // power of prime factor p in n!
{
    ll freq = 0;
    while ((n / p) > 0)
    {
        freq += (n / p);
        n /= p;
    }

    return freq;
}

// calculate the count of power of x in the prime factorization of n
// 2^q q koto arki
int func(int n, int x)
{
    int c = 0;
    while (n % x == 0)
    {
        c++;
        n = n / x;
    }
    return c;
}

const double eps = 1e-9;
int leadingDigitFact(int n, int k)
{
    double fact = 0;

    for (int i = 1; i <= n; i++)
    {
        fact += log10(i);
    }

    double q = fact - floor(fact + eps);

    double B = pow(10, q);

    for (int i = 0; i < k - 1; i++)
    {
        B *= 10;
    }

    return floor(B + eps);
}

int leadingDigit_power(ll n, ll k, ll digits) // power
{
    double val = k * log10(n);

    double p = val - floor(val + eps);

    double ans = pow(10, p);
    for (int i = 0; i < digits - 1; i++)
    {
        ans *= 10;
    }

    return floor(ans + eps);
}

int leadingDigit(ll n, ll digits) // number
{
    double val = log10(n);

    double p = val - floor(val + eps);

    double ans = pow(10, p);

    for (int i = 0; i < digits - 1; i++)
        ans *= 10;

    return floor(ans + eps);
}

int dayofweek(int d, int m, int y) // day
{
    static int t[] = {0, 3, 2, 5, 0, 3,
                      5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 +
            y / 400 + t[m - 1] + d) %
           7;
}

const ll eps = 10e-9;
int factorialDigit(int n)
{
    double x = 0;
    for (int i = 1; i <= n; i++)
    {
        x += log10(i);
    }
    int res = x + 1 + eps;
    return res;
}

int factorialDigitExtended(int n, int base)
{
    double x = 0;
    for (int i = 1; i <= n; i++)
    {
        x += log10(i) / log10(base); // Base Conversion
    }
    int res = x + 1 + eps;
    return res;
}

/* to avoid tle
 logs.push_back(0);
    for(int i=1;i<=1e6;i++)
        logs.push_back(logs[i-1]+log10(i));
    ll ans=(logs[a]/log10(b))+1+eps;
    */
// you can store like this

vector<pair<ll, ll>> pfactors_pair(ll n)
{
    vector<pair<ll, ll>> result;

    for (ll i = 0; i < primes.size() && primes[i] <= sqrt(n); i++)
    {
        ll freq = 0;
        while (n % primes[i] == 0)
        {
            freq++;
            n /= primes[i];
        }
        if (freq)
            result.push_back({primes[i], freq});
    }
    if (n > 1)
        result.push_back({n, 1});

    return result;
}

// const vector<int>& v
ll binarysearch(ll key)
{

    vector<ll> v; ///////////////

    ll l = 0, r = v.size() - 1;
    ll res = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (v[mid] == key)
        {
            res = mid;
            r = mid - 1;
        }
        else if (v[mid] > key)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return res;
}

double square_root(double n)
{
    double l = 0, r = (n >= 1) ? n : 1;
    while (l + eps < r)
    {
        double mid = (l + r) / 2;
        if (mid * mid > n + eps)
        {
            r = mid;
        }
        else if (mid * mid + eps < n)
        {
            l = mid;
        }
        else /* mid * mid == n */
        {
            return mid;
        }
    }
}

int binary_search_lowerbound(const vector<int> &a, int key)
{
    int res = a.size();
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] >= key)
        {
            res = mid;
            r = mid - 1;
        }
        else /* if (a[mid] < key) */
        {
            l = mid + 1;
        }
    }
    return res;
}

// upperbound(x) = position of first element y such that y > x
int binary_search_upperbound(const vector<int> &a, int key)
{
    int res = a.size();
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] > key)
        {
            res = mid;
            r = mid - 1;
        }
        else /* if (a[mid] < key) */
        {
            l = mid + 1;
        }
    }
    return res;
}

int countSetBits(int n) // binary 1s
{
    // base case
    if (n == 0)
        return 0;
    else
        return 1 + countSetBits(n & (n - 1));
}
// __builtin_popcount()

string dec_to_bin(int n)
{
    string ret = "";
    for (int i = 31; i >= 0; i--)
    {
        int k = 1 << i;
        ret += (n & k) ? '1' : '0';
    }
    return ret;
}

int bin_to_dec(string s)
{
    int ret = 0;
    for (int i = 0; i < 32; i++)
        ret = (2 * ret) + s[i] - '0';
    return ret;
}

int convert(int n)
{ // binary
    int dec = 0, i = 0, rem;

    while (n != 0)
    {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }

    return dec;
}

// pair factorize
vector<pair<int, int>> factorize(int n)
{
    vector<pair<int, int>> factors;
    int sqrtn = sqrt(n);
    for (int i = 0; i < primes.size() && primes[i] <= sqrtn; i++)
    {
        if (n % primes[i] == 0)
        {
            int cnt = 0;
            while (n % primes[i] == 0)
            {
                cnt++;
                n /= primes[i];
            }
            factors.push_back(make_pair(primes[i], cnt));
            sqrtn = sqrt(n);
        }
    }
    if (n != 1)
    {
        factors.push_back(make_pair(n, 1));
    }
    return factors;
}

//////////////
// valid triangles
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        ll k = j;
        ll ind = lower_bound(v.begin(), v.end(), v[i] + v[j]) - v.begin();
        ind--;
        if (ind != j)
            ans += (ind - j);
    }
}

/* Sliding Window Maximum  */
void subarray()
{
    int n, k;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    deque<int> dq;

    int i = 0;
    for (; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for (; i < n; i++)
    {
        cout << arr[dq.front()] << ' ';

        while (!dq.empty() && dq.front() <= (i - k))
            dq.pop_front();

        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << ' ';
    cout << endl;
}

bool isBalanced(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk.push(s[i]);
        else
        {
            if (stk.empty())
                return false;
            else if (s[i] == ')' && stk.top() != '(')
                return false;
            else if (s[i] == ']' && stk.top() != '[')
                return false;
            else if (s[i] == '}' && stk.top() != '{')
                return false;
            stk.pop();
        }
    }
    if (stk.empty())
        return true;
    return false;
}

/* substring occurence  dynamic programming dp */
int count(string a, string b)
{
    int m = a.length();
    int n = b.length();

    int lookup[m + 1][n + 1] = {{0}};

    for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;

    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] % mod +
                               lookup[i - 1][j] % mod;

            else
                lookup[i][j] = lookup[i - 1][j] % mod;
        }
    }

    return lookup[m][n] % mod;
}

/* string techniques */
//  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
//  s2.erase(remove(s2.begin(),s2.end(),' '),s2.end());
//  lower case erase

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
                                                                  /* length of greatest subarray with a given sum */
                                                                  sum = 0;
int l = 0, res = -1;
for (int r = 0; r < n; ++r)
{
    sum += v[r];
    while (sum > k)
    {
        sum -= v[l];
        l++;
    }
    if (sum == k)
        res = max(res, r - l + 1);
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
                                                                  /* minimal subarray length which has sum greater than s */
                                                                  for (int i = 0; i < n; i++)
{
    sum += v[i];
    while (sum >= s)
    {
        ans = min(ans, i + 1 - ind);
        flag = true;
        sum -= v[ind++];
    }
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

                                                                  /* for a given array, all possible combination */
                                                                  for (int i = 0; i < (1 << arr.size()); i++)
{
    cnt = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (i & (1 << j))
        {
            cout << arr[j] << endl;
            cnt++;
        }
    }
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

                                                                  /* Largest Sum Contiguous Subarray (Kadane’s Algorithm) */
                                                                  int
                                                                  maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
                                                                  // Returns true if str1 is smaller than str2.
                                                                  bool
                                                                  isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++)
    {
        // Do school mathematics, compute difference of
        // current digits
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);
        carry = 0;
        str.push_back(sub + '0');
    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

                                                                  /* add string numbers */

                                                                  void
                                                                  addnumbers(string &a, string &b)
{
    int carry = 0;
    string ans = "";
    reverse(range(a));
    reverse(range(b));
    for (int i = 0; i < max(a.size(), b.size()); i++)
    {
        int x = 0, y = 0;
        if (i < a.size())
            x = a[i] - '0';
        if (i < b.size())
            y = b[i] - '0';
        int sum = x + y + carry;
        carry = sum / 10;
        sum %= 10;
        ans += sum + '0';
    }
    if (carry)
        ans += carry + '0';
    reverse(range(ans));
    omitleadingzeroes(ans);
    cout << ans << endl;
}

struct DSU
{
    vector<int> rep; // store negation of size of representative
    int cc;
    DSU(int sz)
    {
        rep = vector<int>(sz, -1);
        cc = sz - 1;
    }

    // get representive component (uses path compression)
    int get(int x) { return rep[x] < 0 ? x : rep[x] = get(rep[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -rep[get(x)]; }

    bool unite(int x, int y)
    { // union by size
        x = get(x), y = get(y);
        if (x == y)
            return false;
        if (rep[x] > rep[y])
            swap(x, y); // rep[x] less means bigger size
        rep[x] += rep[y];
        cc--;
        rep[y] = x;
        return true;
    }
};

bool is_bipartite(const vector<vector<int>> &adj)
{
    vector<int> color(adj.size(), -1);
    queue<int> q;
    color[0] = 0, q.push(0);

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (color[v] == color[u])
                return false;
            if (color[v] != -1)
                continue;
            color[v] = color[u] ^ 1;
            q.push(v);
        }
    }
}

void bfs(int source)
{
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i = 0; i < graph[f].size(); i++)
        {
            int child = graph[f][i];
            if (dist[child] == -1)
            {
                dist[child] = dist[f] + 1;
                q.push(child);
            }
        }
    }
}

void dfs(int source)
{
    vis[source] = 1;
    for (int i = 0; i < graph[source].size(); i++)
    {
        int child = graph[source][i];
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};
int di[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dj[] = {1, 0, -1, 1, 0, -1, 1, -1};

//////////////
//////////////
// num of shortest way
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    queue<int> q;

    q.push(1);
    vis[1] = true;
    dist[1] = 0;
    path[1] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto x : graph[u])
        {
            if (!vis[x])
            {
                dist[x] = dist[u] + 1;
                vis[x] = true;
                q.push(x);
            }
            if (dist[x] == dist[u] + 1)
            {
                path[x] += path[u];
                path[x] %= mod;
            }
        }
    }
    cout << path[n] << endl;
}
//////////////
//////////////

vector<int> adj[200001];
int firstMax[200001];  // to store first-max length.
int secondMax[200001]; // to store second-max length.
int c[200001];         // to store child for path of max length.

// calculate for every node x the maximum
// length of a path that goes through a child of x
void dfs(int v, int p)
{
    firstMax[v] = 0;
    secondMax[v] = 0;
    for (auto x : adj[v])
    {
        if (x == p)
            continue;
        dfs(x, v);
        if (firstMax[x] + 1 > firstMax[v])
        {
            secondMax[v] = firstMax[v];
            firstMax[v] = firstMax[x] + 1;
            c[v] = x;
        }
        else if (firstMax[x] + 1 > secondMax[v])
        {
            secondMax[v] = firstMax[x] + 1;
        }
    }
}

// calculate for every node x the
// maximum length of a path through its parent p
void dfs2(int v, int p)
{
    for (auto x : adj[v])
    {
        if (x == p)
            continue;
        if (c[v] == x)
        {
            if (firstMax[x] < secondMax[v] + 1)
            {
                secondMax[x] = firstMax[x];
                firstMax[x] = secondMax[v] + 1;
                c[x] = v;
            }
            else
            {
                secondMax[x] = max(secondMax[x], secondMax[v] + 1);
            }
        }
        else
        {
            secondMax[x] = firstMax[x];
            firstMax[x] = firstMax[v] + 1;
            c[x] = v;
        }
        dfs2(x, v);
    }
}

int main()
{
    FIO;
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    dfs2(1, -1);

    for (int i = 1; i <= n; i++)
    {
        cout << firstMax[i] << " ";
    }
    return 0;
}
//////////////
//////////////
//////////////
//////////////
//////////////

// dp
int lcs(int i, int j, string &S, string &W)
{
    if (i == S.size() || j == W.size())
        return 0;

    if (mem[i][j] != EMPTY_VALUE)
    {
        return mem[i][j];
    }

    int ans = 0;
    if (S[i] == W[j])
    {
        ans = 1 + lcs(i + 1, j + 1, S, W);
    }
    else
    {
        int val1 = lcs(i + 1, j, S, W);
        int val2 = lcs(i, j + 1, S, W);

        ans = max(val1, val2);
    }

    mem[i][j] = ans;
    return mem[i][j];
}

int lcs(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

string ans = "";
int i = n, j = m;
while (i > 0 && j > 0)
{
    if (s[i - 1] == t[j - 1])
    {
        ans += s[i - 1];
        i--;
        j--;
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
}
reverse(ans.begin(), ans.end());

// grid
ll grid(int x, int y)
{
    if (x == 1 and y == 1)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];

    ll ways = 0;
    if (x - 1 >= 1)
        ways += solve(x - 1, y);
    if (y - 1 >= 1)
        ways += solve(x, y - 1);

    return dp[x][y] = ways;
}

int knapsack(int i, int max_size)
{
    if (i >= n)
        return 0;

    if (dp[i][max_size] != -1)
        return dp[i][max_size];

    int val1 = 0, val2 = 0;

    if (max_size - sz[i] >= 0)
    {
        val1 = value[i] + knapsack(i + 1, max_size - sz[i]);
    }
    val2 = knapsack(i + 1, max_size);

    return dp[i][max_size] = max(val1, val2);
}
// iterative 1d knapsack
for (int i = 0; i < N; i++)
{
    for (int j = B; j >= 0; j--)
    {
        if (j - W[i] >= 0)
        {
            dp[j] = max(dp[j], dp[j - W[i]] + P[i]);
        }
    }
}

// iterative 2d dp

int n, m;
vector<int> val(n);
vector<int> wt(n);
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

for (int i = 0; i < n; i++)
    cin >> val[i];
for (int i = 0; i < n; i++)
    cin >> wt[i];

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= m; j++) // j is the capacity
    {
        if (wt[i - 1] <= j)
        {
            dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        }
        else
            dp[i][j] = dp[i - 1][j];
    }
}
cout << dp[n][m] << endl;

////////////////////
long long dp[n + 1][w + 1];

for (int i = 0; i < 2; i++)
{
    dp[i][0] = 0;
}
for (int i = 0; i <= w; i++)
{
    dp[0][i] = 0;
}

for (int i = 1; i <= n; i++)
{

    for (int j = 1; j <= w; j++)
    {
        if (j - weight[i] >= 0)
        {
            dp[i & 1][j] = max(dp[~i & 1][j], dp[~i & 1][j - weight[i]] + val[i]);
        }
        else
        {
            dp[i & 1][j] = dp[~i & 1][j];
        }
    }
}
cout << dp[n & 1][w] << '\n';

// knapsack 2

ll solve(int i, ll curr)
{
    if (i == n)
        return curr == 0 ? 0 : inf;

    if (dp[i][curr] != -1)
        return dp[i][curr];

    ll ans = inf;
    if (curr - val[i] >= 0)
        ans = min(ans, weight[i] + solve(i + 1, curr - val[i]));
    ans = min(ans, solve(i + 1, curr));

    return dp[i][curr] = ans;
}

ll find(ll val)
{

    for (int i = val; i >= 0; i--)
    {
        if (solve(0, i) <= w)
            return i;
    }
    return 0;
}

/////////////

int editDistance(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int insert = dp[i][j - 1];
                int remove = dp[i - 1][j];
                int replace = dp[i - 1][j - 1];
                dp[i][j] = 1 + min({insert, remove, replace});
            }
        }
    }
    return dp[m][n];
}

// minimum number of characters that must be inserted into S to make it a palindrome.
string s;
cin >> s;
int n = s.size();
string s1 = s;
reverse(range(s1));

cout << n - lcs(s, s1, n, n) << endl;

// num of occurunces of string
ll solve(int i, int j)
{
    if (i >= n)
        return j >= 8;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = 0;
    if (s[j] == t[i])
    {
        ans += solve(i + 1, j + 1);
    }
    ans += solve(i + 1, j);
    return dp[i][j] = ans % mod;
}
////

// priority queue greater
priority_queue<int, vector<int>, greater<int>> gq;
while (!g.empty())
{
    cout << ' ' << g.top();
    g.pop();
}
cout << '\n';
set<int, greater<int>> s1;
////////
/////////
int sumofdigits(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> num(n);
    takeInput(num);
    set<int> ind;
    for (int i = 0; i < n; i++)
    {
        ind.insert(i + 1);
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r;
            cin >> l >> r;

            auto itr = ind.lower_bound(l);
            set<int> s;
            while (itr != ind.end() && *itr <= r)
            {
                num[(*itr) - 1] = sumofdigits(num[(*itr) - 1]);
                if (num[(*itr) - 1] < 10)
                {
                    s.insert((*itr));
                }
                itr++;
            }
            for (auto x : s)
            {
                ind.erase(ind.find(x));
            }
        }
        else
        {
            int x;
            cin >> x;
            cout << num[x - 1] << endl;
        }
    }
}
//////
//////

int pcnt[1000001];
for (int i = 2; i <= 1000000; i++)
{
    if (pcnt[i] == 0)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            pcnt[j]++;
        }
    }
}
int cnt[1000001][6];
for (int i = 2; i <= 1000000; i++)
{
    if (pcnt[i] <= 5)
        cnt[i][pcnt[i]]++;
    for (int j = 1; j <= 5; j++)
    {
        cnt[i][j] = cnt[i - 1][j];
    }
}
int a, b, k;
cin >> a >> b >> k;
cout << cnt[b][k] - cnt[a - 1][k] << endl;
///////////

nCr = n ! / (r !*(n - r) !)
                nPr = n ! / (n - r) !

                      int
                      fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

int nPr(int n, int r)
{
    return fact(n) / fact(n - r);
}

int nCr(int n, int r)
{
    // If r is greater than n, return 0
    if (r > n)
        return 0;
    // If r is 0 or eq  ual to n, return 1
    if (r == 0 || n == r)
        return 1;
    // Initialize the logarithmic sum to 0
    double res = 0;
    // Calculate the logarithmic sum of the numerator and denominator using loop
    for (int i = 0; i < r; i++)
    {
        // Add the logarithm of (n-i) and subtract the logarithm of (i+1)
        res += log(n - i) - log(i + 1);
    }
    // Convert logarithmic sum back to a normal number
    return (int)round(exp(res));
}

ll ncr()

    ll invMod(ll a)
{
    return binExpRecurMod(a, mod - 2, mod);
}

const int N = 3e6 + 5;
ll fact[N];

ll ncr(ll n, ll r)
{
    return fact[n] * (invMod(fact[r]) * invMod(fact[n - r]) % mod) % mod;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }

    ll ans = ncr(n + m - 1, n - 1);
    cout << ans << endl;
}

////////

lcs
    string
    check(string x, string y)
{
    if (x.size() > y.size())
        return x;
    else if (x.size() < y.size())
        return y;
    else
        return min(x, y);
}

for (int i = 0; i <= n; i++)
{
    for (int j = 0; j <= m; j++)
    {
        if (i == 0 || j == 0)
        {
            dp[i][j] = "";
        }
        else if (a[i - 1] == b[j - 1])
        {
            dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
        }
        else
        {
            string str = check(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = str;
        }
    }
}
cout << "Case " << ++kas << ": ";
if (dp[n][m].size() == 0)
    cout << ":(" << endl;
else
    cout << dp[n][m] << endl;

//  the total number of ways to remove letters from W such that it becomes a palindrome.
string s;
ll solve(int i, int j)
{

    if (i > j)
        return 0;
    if (i == j)
        return 1;

    ll &ans = dp[i][j];
    if (ans != -1)
        return ans;

    if (s[i] == s[j])
        return ans = solve(i + 1, j) + solve(i, j - 1) + 1;
    else
        return ans = solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);
}

// the minimum number of characters required to make string to a palindrome.
string s;
int dp[102][102];
int solve(int l, int r)
{
    if (l >= r)
        return 0;

    int &ans = dp[l][r];
    if (ans != -1)
        return ans;

    ans = INT_MAX;

    if (s[l] == s[r])
        ans = solve(l + 1, r - 1);
    else
        ans = (ans, min(solve(l + 1, r), solve(l, r - 1))) + 1;

    return ans;
}

// code dp
const int N = 5000 + 5;
int dp[N];
string s;
int solve(int i)
{
    if (i == s.size())
        return 1;
    if (dp[i] != -1)
        return dp[i];

    int dig1 = s[i] - '0';
    int val = 0;
    if (dig1 != 0)
    {
        val = solve(i + 1);
        if (i + 1 < s.size())
        {
            int num = dig1 * 10 + s[i + 1] - '0';
            if (num <= 26)
            {
                val += solve(i + 2);
            }
        }
    }

    return dp[i] = val;
}
// choice
int n;
vector<int> one, two;
ll solve(int choice, int pos)
{
    if (pos >= n)
        return 0;
    if (dp[choice][pos] != -1)
        return dp[choice][pos];

    ll ans = 0;
    if (choice == 1)
    {
        ans = one[pos] + solve(2, pos + 1);
    }
    if (choice == 2)
    {
        ans = two[pos] + solve(1, pos + 1);
    }
    ans = max(ans, solve(choice, pos + 1));

    return dp[choice][pos] = ans;
}

// rgb
ll dp[205][205][205];
int r, g, b;
vector<ll> vr(205), vg(205), vb(205);

ll solve(int i, int j, int k)
{
    if (i == r && j == g && k == b)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    ll ans = -1e18;
    if (i != r && j != g)
        ans = max(ans, solve(i + 1, j + 1, k) + vr[i] * vg[j]);
    if (i != r && k != b)
        ans = max(ans, solve(i + 1, j, k + 1) + vr[i] * vb[k]);
    if (j != g && k != b)
        ans = max(ans, solve(i, j + 1, k + 1) + vg[j] * vb[k]);

    if (ans == -1e18)
        ans = 0LL;

    return dp[i][j][k] = ans;
}

// shortest path dag
int w[MAX_N][MAX_N];
int mem[MAX_N];

int f(int u, int n)
{
    if (u == n - 1)
    {
        return 0;
    }

    if (mem[u] != EMPTY_VALUE)
    {
        return mem[u];
    }

    int ans = INF;
    for (int v = 0; v < n; v++)
    {
        if (w[u][v] != 0)
        {
            ans = min(ans, f(v, n) + w[u][v]);
        }
    }

    mem[u] = ans;
    return mem[u];
}

// NUMBER OF different WAYS TO MAKE A SUM
int dp[7][10000];
int func(int ind, int amount)
{
    if (amount == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int ways = 0;
    for (int coin = 0; coin <= amount; coin += arr[ind])
    {
        ways += func(ind - 1, amount - coin);
    }

    return dp[ind][amount] = ways;
}

// number of distinct ways to make a sum
vector<int> coins;

ll memo[1000000 + 10];
ll dpp(int x)
{
    if (x == 0)
        return 1;

    if (memo[x] != -1)
        return memo[x];

    ll ret = 0;
    for (int c : coins)
    {
        if (x - c < 0)
            continue;
        ret += dpp(x - c);
        ret %= mod;
    }

    memo[x] = ret;

    return ret;
} // 2 3 3 .. 3 2 3 these are diff ways
///

// minimum number of coins to make a sum
int memo[1000000 + 10];
int dp(int x)
{
    if (x == 0)
        return 0;

    if (memo[x] != -1)
        return memo[x];

    int ret = 1e9;
    for (int c : coins)
    {
        if (x - c < 0)
            continue;
        ret = min(ret, dp(x - c));
    }

    ret += 1;

    memo[x] = ret;

    return ret;
}

// the number of distinct ordered ways you can produce a money sum x using the available coins.
vector<int> coins;

ll memo[1000000 + 10];
int dp(int X, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int x = 0; x <= X; x++)
        {
            if (x == 0)
                memo[x] = 1;
            else if (i == 0)
                memo[x] = 0;
            else
            {
                memo[x] = memo[x];
                if (x - coins[i] >= 0)
                    memo[x] = (memo[x] + memo[x - coins[i]]) % mod;
            }
        }
    }

    return memo[X];
}

// cses removing digits
You are given an integer n
    .On each step,
    you may subtract one of the digits from the number.

    How many steps are required to make the number equal to 0
    ?

    vector<int>
        minSteps(n + 1, 1e9);
minSteps[0] = 0;
for (int i = 1; i <= n; i++)
{
    int tmp = i;
    while (tmp)
    {
        int d = tmp % 10;
        tmp /= 10;
        minSteps[i] = min(minSteps[i], minSteps[i - d] + 1);
    }
}
cout << minSteps[n] << endl;

// frog
ll n, k;
ll v[(int)1e5 + 10];
ll dp[(int)1e5 + 10];
ll solve(ll pos)
{
    if (pos == 0)
        return 0;
    if (dp[pos] != -1)
        return dp[pos];

    ll val = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        // cout<<pos<<' '<<i<<endl;
        if (pos - i >= 0)
        {
            // cout<<pos<<' '<<k<<endl;
            val = min(abs(v[pos] - v[pos - i]) + solve(pos - i), val);
        }
    }

    return dp[pos] = val;
}

// dice
int DP[MAXN], n;

int compute(int left)
{
    if (DP[left] != 0)
    {
        return DP[left];
    }
    for (int i = 1; i <= 6; i++)
    {
        if (left - i >= 0)
        {
            DP[left] += compute(left - i);
            DP[left] %= MOD;
        }
    }
    return DP[left];
}

// slimes
ll dp[405][405];
ll presum[405];
int slimes[405];

ll getSum(int l, int r)
{
    if (l == 0)
        return presum[r];
    return presum[r] - presum[l - 1];
}

ll solve(int l, int r)
{
    if (l == r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    ll ans = INT64_MAX;
    for (int i = l; i < r; i++)
    {
        ans = min(ans, getSum(l, r) + solve(l, i) + solve(i + 1, r));
    }

    return dp[l][r] = ans;
}

// coin probability
double dp[3001][3001];
double val[3001];
bool vis[3001][3001];
int n;

double solve(int i, int cnt)
{
    if (i == n)
        return cnt > n / 2;

    double check = dp[i][cnt];
    if (vis[i][cnt])
        return dp[i][cnt];

    vis[i][cnt] = true;

    double val1 = val[i] * solve(i + 1, cnt + 1);

    val1 += (1 - val[i]) * solve(i + 1, cnt);

    return dp[i][cnt] = val1;
}

// game dp
int dp[(int)1e5 + 5];
vector<int> v;

int solve(int stones)
{
    if (stones == 0)
        return 0;

    if (dp[stones] != -1)
        return dp[stones];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (stones - v[i] >= 0)
        {
            //  res+=!solve(stones - v[i]);
            res |= !solve(stones - v[i]);
        }
    }

    return dp[stones] = res;
}

// deque
ll dp[3005][3005][2];

ll solve(int i, int j, int k)
{
    if (i > j)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (k)
    {
        dp[i][j][k] = max(v[i] + solve(i + 1, j, !k), v[j] + solve(i, j - 1, !k));
    }
    else
    {
        dp[i][j][k] = min(-v[i] + solve(i + 1, j, !k), -v[j] + solve(i, j - 1, !k));
    }
    return dp[i][j][k];
}

// is it tree
void dfs(int node)
{
    if (visited[node])
    {
        flag = true;
        return;
    }
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

if (n - 1 != m)
{
    cout << "NO" << endl;
    return 0;
}

dfs(1);
if (flag)
    goto label;

for (int i = 1; i <= n; i++)
{
    if (!visited[n])
    {
        flag = true;
        break;
    }
}

label : if (flag) cout << "NO" << endl;
else cout << "YES" << endl;

// bicolor
bool bfs_bicolor(int source)
{
    memset(color, -1, sizeof(color));
    queue<int> q;
    color[source] = 1;
    q.push(source);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i = 0; i < graph[f].size(); i++)
        {
            int child = graph[f][i];
            if (color[f] == color[child])
            {
                return false;
            }
            if (color[child] == -1)
            {
                color[child] = 1 - color[f];
                q.push(child);
            }
        }
    }
    return true;
}

void bfs(int src)
{
    if (g[src].size() == 0)
        return;

    queue<int> q;
    q.push(src);
    color[src] = 1;
    vamp++;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int i = 0; i < g[f].size(); i++)
        {
            int child = g[f][i];

            if (color[child] == -1)
            {
                q.push(child);

                if (color[f] == 1)
                {
                    color[child] = 0;
                    lyk++;
                }
                else
                {
                    color[child] = 1;
                    vamp++;
                }
            }
        }
    }
}

stack<int> stk;
void topsort(int v)
{
    visited[v] = true;

    for (auto u : graph[v])
        if (!visited[u])
            topsort(u);
    stk.push(v);
}

// money divide
bool bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    cnt++;
    cost += money[source];
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i = 0; i < graph[f].size(); i++)
        {
            int child = graph[f][i];
            if (visited[child] == false)
            {
                cnt++;
                cost += money[child];
                visited[child] = true;
                q.push(child);
            }
        }
    }
    if (cost % cnt == 0)
    {
        s.insert(cost / cnt);
        return true;
    }
    return false;
}

// jane and frost
char graph[N][N];
int fire[N][N];
int jane[N][N];

int r, c, kas;

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

bool isValid(int x, int y)
{
    return (x >= 0 and x < r and y >= 0 and y < c and graph[x][y] != '#');
}

bool boundary(int x, int y)
{
    return (x == 0 or x + 1 == r or y == 0 or y + 1 == c);
}

void bfs_fire()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (graph[i][j] == 'F')
            {
                q.push({i, j});
                fire[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto coord = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = coord.first + dx[i];
            int y = coord.second + dy[i];
            if (isValid(x, y) and fire[x][y] == -1)
            {
                fire[x][y] = fire[coord.first][coord.second] + 1;
                q.push({x, y});
            }
        }
    }
    //  for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<fire[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
}

void bfs(int a, int b)
{
    queue<pair<int, int>> q;

    q.push({a, b});
    jane[a][b] = 0;

    while (!q.empty())
    {
        auto coord = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = coord.first + dx[i];
            int y = coord.second + dy[i];
            int dist = jane[coord.first][coord.second];
            if (isValid(x, y) and jane[x][y] == -1 and (fire[x][y] == -1 or fire[x][y] > dist + 1))
            {
                jane[x][y] = dist + 1;
                q.push({x, y});
            }
        }
    }
}

void solve()
{
    cin >> r >> c;
    memset(fire, -1, sizeof(fire));
    memset(jane, -1, sizeof(jane));

    pair<int, int> s;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'J')
            {
                s.first = i, s.second = j;
            }
        }
    }

    bfs_fire();
    bfs(s.first, s.second);

    int ans = INT_MAX;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (boundary(i, j) and jane[i][j] != -1)
            {
                ans = min(ans, jane[i][j] + 1);
            }
        }
    }
    cout << "Case " << ++kas << ": ";
    if (ans == INT_MAX)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

struct Point
{
    int x, y;
};

// To find orientation of ordered triplet (p1, p2, p3).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p1, Point p2, Point p3)
{
    // See 10th slides from following link for derivation
    // of the formula
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);

    if (val == 0)
        return 0; // collinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// ncr
long long c[40][40];

for (int i = 0; i < 40; i++)
    c[i][0] = 1;

for (int i = 1; i < 40; i++)
    for (int j = 1; j <= i; j++)
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];

// GRAPH CYCLE PRINT
int start = -1, stop = -1;
void dfs(int u, int p, vector<int> &color, vector<int> &parent)
{
    // cout<<u<<" "<<p<<endl;
    if (color[u] == 2)
        return;

    if (color[u] == 1)
    {
        start = u;
        stop = p;
        return;
    }

    parent[u] = p;
    color[u] = 1;
    for (int v : adj[u])
    {
        // if(v == parent[u])
        //     continue; //??????
        dfs(v, u, color, parent);
        if (start != -1)
            return;
    }
    color[u] = 2;
}
- 1 hole impossible
    vector<int>
        arr;
arr.push_back(start);
for (int i = stop; i != start; i = parent[i])
{
    arr.push_back(i);
}
// arr.push_back(start);
reverse(range(arr));
== == == == == == == == == == == == == =
                                           == == == == == == == == == == == == == == == == == =
                                                                                                  == == == == == == == == == == == == == == == == == == == ==
                                                                                                  // ternary search
                                                                                                  ll l = -1e10,
                                    r = 1e10;
while (l <= r)
{
    ll mid1 = l + (r - l) / 3;
    ll mid2 = r - (r - l) / 3;

    ll val1 = check(mid1);
    ll val2 = check(mid2);
    if (val1 < val2)
    {
        r = mid2 - 1;
    }
    else
    {
        l = mid1 + 1;
    }

    ////
    const int MAXN = 1e7 + 5;
    int spf[MAXN];

    void sieve(int n)
    {
        spf[1] = 1;
        for (int i = 2; i < MAXN; i++)
            spf[i] = i;

        for (int i = 4; i < MAXN; i += 2)
            spf[i] = 2;

        for (int i = 3; i * i < MAXN; i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j < MAXN; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
    }

    void factorize(int n, vector<int> &temp)
    {
        int prev = -1;
        while (n != 1)
        {
            if (spf[n] != prev)
            {
                temp.emplace_back(spf[n]);
                prev = spf[n];
            }
            n = n / spf[n];
        }
    }
/////////////

const int N = 2e5 + 5, LG = 18;
int64_t st[N][LG], lgs[N];

void sparse_table(vector<int>& a, int n) {
    for (int i = 0; i < n; ++i) {
        st[i][0] = a[i];
    }
    for (int i = 0; i <= n; ++i) {
        lgs[i] = __lg(i);
    }

    for (int j = 1; j < LG; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            st[i][j] = (st[i][j - 1] & st[i + (1 << (j - 1))][j - 1]);
            // st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int l, int r) {
    int j = lgs[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

