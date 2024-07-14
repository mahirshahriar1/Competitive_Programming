#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

const double eps = 1e-9;
const int mod = 1e9 + 7;

vector<bool> isprime;
vector<int> primes;

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
    //for every element, using the prev i am storing unique primes
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

bool isSubset(vector<int> &factors1, vector<int> &factors2)
{
    // function checks that f2 is subset of f1
    set<int> s1(factors1.begin(), factors1.end());  
    for (auto x : factors2)
    {
        if (s1.find(x) == s1.end())
        {
            return false;
        }
    }
    return true;
}

bool checkBob(vector<int> &a, vector<int> &b)
{
    int gcd = 0;
    for (auto x : a)
    {
        gcd = __gcd(gcd, x);
    }
    if (gcd == 1)
    {
        //if gcd is 1 no matter the operation, we cannot change A
        return false;
    }

    if (a[0] < b[0])
    {
        //suppose A =  2  and B = 8.. I need to make A = 8
        //Can also be done without swapping but using more if else condition
        swap(a, b);
    }
    if (a[0] % b[0] != 0)
    {
        //if A[0] is not divisible by B[0] then we cannot change A
        //we swapped previously so A[0] will be greater
        //so for A=2 and B=8 after swapping A=8 and B=2 we now can see that 
        // we can make 2 to 8 as it is divisble
        return false;
    }
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] % b[i] != 0)
        {
            //checking the same thing for every element
            return false;
        }
        if (a[i] / b[i] != a[i - 1] / b[i - 1])
        {
            //the ratio of divisibily should be same for every element
            //as we need to multiply or divide every element of A by same number
            return false;
        }
    }

    vector<int> divs;
    factorize(gcd, divs); 

    int val = a.front() / b.front(); //the number by which we need to multiply or divide
    vector<int> divsOfVal;
    factorize(val, divsOfVal);
    
    //checking if the divisors of gcd are subset of divisors of val
    return isSubset(divs, divsOfVal);
}

int kas;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (auto &x : a)
    {
        cin >> x;
    }
    for (auto &x : b)
    {
        cin >> x;
    }

    //trivial
    if (a == b)
    {
        cout << "Case " << ++kas << ": Yes Yes" << endl;
        return;
    }

    //f1 stores primes of every element of a
    //f2 stores primes of every element of b
    vector<int> f1, f2;
    for (int i = 0; i < n; i++)
    {
        factorize(a[i], f1);
        factorize(b[i], f2);
    }

    vector<int> cnt1, cnt2;

    auto work = [&](vector<int> vec, vector<int> &cnt)
    {
        sort(vec.begin(), vec.end());
        int prev = -1;
        for (auto x : vec)
        {
            if (x != prev)
            {
                cnt.emplace_back(x);
                prev = x;
            }
        }
    };

    //there are duplicate primes which i am removing in the work function
    work(f1, cnt1);
    work(f2, cnt2);

    bool alex = isSubset(cnt1, cnt2);
    bool bob = checkBob(a, b);

    cout << "Case " << ++kas << ": ";
    cout << (alex ? "Yes" : "No") << ' ';
    cout << (bob ? "Yes" : "No") << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve(1e7);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}