https://ideone.com/dtDsBS //binary
https://ideone.com/bXkIc6 //binary
https://ideone.com/KpOYVK // prefix

#include <bits/stdc++.h>
using namespace std;

/*vector <int> prime; // Stores generated primes
char sieve[SIZE]; // 0 means prime
void primeSieve ( int n ) {
    sieve[0] = sieve[1] = 1; // 0 and 1 are not prime

    prime.push_back(2); // Only Even Prime
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1; // Remove multiples of 2

    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }

    for ( int i = 3; i <= n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}
*/

/*vector <int> primes;
int isprime[(int)1e8]={0};

void sieve(int n)
{
    isprime[0]=isprime[1]=1;
    primes.push_back(2);
    for(int i=2;i<=n;i+=2)
        isprime[i]=1;

    for(int i=3; i<=n; i+=2)
    {
        if(isprime[i]==0)
        {
            primes.push_back(i);
            for(int j=i;j<=1e7;j+=i)
            {
                isprime[j]=1;
            }
        }
    }

}
*/


vector <bool> isprime;
vector <int> primes;

void sieve(int n) //prime
{
    isprime.assign(n+1,true);

    isprime[0]=isprime[1]=false;

   /* for(int j=4; j<=n; j+=2)
    {
        isprime[j]=false;
    }
    for(int i=3; i*i<=n; i++)
    */

    for(int i=2; i*i<=n; i++)
    {
        if(!isprime[i])
            continue;
        for(int j=i*i; j<=n; j+=i)
        {
            isprime[j]=false;
        }
    }

    for(int i=2;i<=n;i++){
        if(isprime[i])
            primes.push_back(i);
    }

} //O(n log log n)

vector <int> NOD; // number of divisors

void sieve_NOD(int n)
{
    NOD.assign(n+1, 0);

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n; j+=i)
        {
            ++NOD[j];
        }
    }
} // O(n * log n)



vector <int> SOD;
void sieve_SOD(int n){

    SOD.assign(n+1,0);

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
            SOD[j]+=i;
    }

} // O(n * log n)


int GCD(int a, int b)
{
        if(b==0)
            return a;
        return GCD(b,a%b);
} // O(log min(a,b))

int lcm(int a, int b){
    return (a/GCD(a,b))*b;
}

int module(string num, int mod)
{
    int i=0;
    if(num[0]=='-')
        i=1;

    int res=0;
    for( ;i<num.size();i++)
    {
        int d=num[i]-'0';
        res=(res*10)+d;
        res%=mod;
    }
    if(num[0]=='-')
        return -res;
    else
        return res;
}

ll binExpRecur(int a, int b)  //power
{
    if(b==0) return 1;
    ll res= binExpRecur(a,b/2);
    if(b&1)
        return a*res*res;
    else
        return res*res;
}
ll binExpRecurMod(ll a, ll b,ll m)  //pow function
{
    if(b==0) return 1;
    ll res= binExpRecurMod(a,b/2,m);
    if(b&1)
        return a%m*res%m*res%m;
    else
        return res%m*res%m;
}




// O(sqrt (n))
vector<int> divisors(int n) {
    vector<int> div;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i) {
                div.push_back(n / i);
            }
        }
    }
    sort(div.begin(), div.end());
    return div;
}

//more efficient
vector<int> divisors(int n) {
    vector<int> div;
    vector<int> buf; // buffer (temp. storage)
    for (int i = 1; i * i <= n; ++i) {
       if (n % i == 0) {
           div.push_back(i);
           buf.push_back(n / i);
       }
    }
    int from = buf.front() == div.back() ? 1 : 0;
    for (int i = buf.size() - 1; i >= from; --i) {
        div.push_back(buf[i]);
    }
    return div;
}// O(sqrt (n))

int NOD(int n) {
     int cnt = 0;
     for (int i = 1; i * i <= n; ++i) {
         if (n % i == 0) {
             ++cnt;
             if (n / i != i) {
                  ++cnt;
             }
         }
     }
     return cnt;
}// O(sqrt (n))


int SOD(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum+=i;
            if (n / i != i) {
                sum+=n/i;;
            }
        }
    }
    return sum;
}


bool is_prime(int n) {
if(n==1)
    return false;//////////
    for (int i = 2; i *1ll* i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long long int rev(long long int y)
{
    long long int reversed_number=0;
    while(y)
    {
        reversed_number=reversed_number*10+y%10;
        y/=10;

    }
    return reversed_number;
}


vector <int> pfactors(int n)
{
    vector<int> result;
    for(int p=2;p*p<=n;p++)
    {
        while(n%p==0)
        {
            n/=p;
            result.push_back(p);
        }
    }
    if(n>1)
        result.push_back(n);
    return result;
}
---------------
map<int,int> mp;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n>1) mp[n]++;
----------------

vector <int> pfactors_v2(int n) //initialize sieve for this
{
    vector<int> result;
    for(ll p:primes)
    {
        if(p*p>n)
            break;
        while(n%p==0)
        {
            n/=p;
           result.push_back(p);
        }

    }
    if(n>1)
        result.push_back(n);

    return result;
}

vector <pair<ll,ll>> pfactors_pair(ll n)  // prime factor pair
{
    vector<pair<ll,ll>>result;
    for(ll p=2;p*p<=n;p++)
    {
        ll cnt=0;
        if(n%p)
            continue;
        while(n%p==0)
        {
            n/=p;
            ++cnt;
        }
        result.push_back({p,cnt});
    }
    if(n>1)
        result.push_back({n,1});
    return result;
}

vector <pair<ll,ll>> pfactors_pair(ll n)  //initialize sieve for this
{
    vector<pair<ll,ll>>result;
    for(ll p:primes)
    {
        if(p*p>n)
            break;
        if(n%p)
            continue;
        ll exp=0;
        while(n%p==0)
        {
            n/=p;
            exp++;
        }
        result.push_back({p,exp});
    }
    if(n>1)
        result.push_back({n,1});

    return result;
}

int count_pfactor(int n, int limit) //limit prime.size()
{
    int size=sqrt(n) , count(0);
    for(int i=0;priems[i]<=size&&i<limit;i++)
    {
        bool sign=false;
        while(n%primes[i]==0)
        {
            n/=primes[i];
            sign=true;
        }
        size=sqrt(n);
        if(sign)
            count++;
    }
    if(n>1)
        count++;
    return count;
}


vector <int> p_factors; //forthright
void factorize( int n ) {
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
             // if ( sieve[n] == 0 ) break; /*Checks if n is prime or not*/
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                factors.push_back(prime[i]);
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        factors.push_back(n);
    }
}  //forthright


int SOD_pfactor( int n ) {
    int res=1;
    for(int p=2;p*p<=n;p++)
    {
        int tempSum = 1;
        int x = 1;
        while(n%p==0)
        {
              n /= p;
              x *= p;
              tempSum += x;
        }
       res *= tempSum;
    }
    if(n>1)
        res *= ( n + 1 );
    return res;
}

int SOD_pfactor_v2( int n ) {
    int res = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 ) {
        res *= ( n + 1 ); // Need to multiply (p^0+p^1)
    }
    return res;
}


int NOD_pfactor( int n ) {
    int sqrtn = sqrt ( n );
    int res = 1;
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int p = 0; // Counter for power of prime
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++; // Increase it by one at end
            res *= p; // Multiply with answer
        }
    }
    if ( n != 1 ) {
        res *= 2; // Remaining prime has power p^1. So multiply with 2/
    }
    return res;
}

ll pfactors_NOD(ll n)
{
    ll result=1;
    ll sqrtn=sqrt(n);
    for(int p=2;p<=sqrtn;p++)
    {
        ll cnt=0;
        while(n%p==0)
        {
            n/=p;
           cnt++;
        }
        cnt++;
        result*=cnt;
        sqrtn=sqrt(n);
    }
    if(n>1)
        result*=2;
    return result;
}



ll trailingZeroes(ll n)
{
    ll ans=0;
    ll p=5;
    while((n/p)>0)
    {
        ans+=(n/p);
        n/=5;
    }

    return ans;
}  // min(2,5) pair


// To find the power of a prime p in
// factorial N
ll frequency(ll n,ll p) //power of prime factor p in n! 
{
    ll freq=0;
    while((n/p)>0)
    {
        freq+=(n/p);
        n/=p;
    }

    return freq;
}

// calculate the count of power of x in the prime factorization of n
//2^q q koto arki
int func(int n, int x)
{
    int c = 0;
    while(n % x == 0)
    {
        c++;
        n = n / x;
    }
    return c;
}



const double eps = 1e-9;
int leadingDigitFact ( int n, int k ) {
    double fact = 0;


    for ( int i = 1; i <= n; i++ ) {
        fact += log10 ( i );
    }


    double q = fact - floor ( fact+eps );

    double B = pow ( 10, q );


    for ( int i = 0; i < k - 1; i++ ) {
        B *= 10;
    }


    return floor(B+eps);
}

int leadingDigit_power(ll n, ll k, ll digits )  //power
{
    double val=k*log10(n);

    double p=val-floor(val+eps);

    double ans=pow(10,p);
     for ( int i = 0; i < digits - 1; i++ ) {
        ans *= 10;
    }

    return floor(ans+eps);
}

int leadingDigit(ll n,ll digits)  //number
{
    double val=log10(n);

    double p=val-floor(val+eps);

    double ans=pow(10,p);

    for(int i=0;i<digits-1;i++)
         ans *= 10;

    return floor(ans+eps);
}



int dayofweek(int d, int m, int y)  //day
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y / 4 - y / 100 +
             y / 400 + t[m - 1] + d) % 7;
}

const ll eps=10e-9;
int factorialDigit ( int n ) {
    double x = 0;
    for ( int i = 1; i <= n; i++ ) {
        x += log10 ( i );
    }
    int res = x + 1 + eps;
    return res;
}

int factorialDigitExtended ( int n, int base ) {
    double x = 0;
    for ( int i = 1; i <= n; i++ ) {
        x += log10 ( i ) / log10(base); // Base Conversion
    }
    int res = x + 1 + eps;
    return res;
}

/* to avoid tle
 logs.push_back(0);
    for(int i=1;i<=1e6;i++)
        logs.push_back(logs[i-1]+log10(i));
    ll ans=(logs[a]/log10(b))+1+eps;
    */ //you can store like this

vector <pair<ll,ll>> pfactors_pair(ll n)        
{
      vector<pair<ll,ll>>result;

    for(ll i=0; i<primes.size()&&primes[i]<=sqrt(n); i++)
    {
        ll freq=0;
        while(n%primes[i]==0)
        {
            freq++;
            n/=primes[i];
        }
        if(freq)
            result.push_back({primes[i],freq});

    }
    if(n>1)
        result.push_back({n,1});

    return result;

}




const double eps = 1e-9;

bool test_less(double x, double y) {
    return x + eps < y;
}

bool test_greater(double x, double y) {
    return x > y + eps;
}

bool test_equal(double x, double y) {
    return abs(x - y) < eps;
}


//const vector<int>& v
ll binarysearch(ll key)
{

    vector<ll> v; ///////////////

    ll l=0, r=v.size()-1;
    ll res=-1;
    while(l<=r){
        ll mid = (l + r) / 2;
        if (v[mid] == key){
            res=mid;
            r=mid-1;
        }else if(v[mid]>key){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    return res;
}


double square_root(double n) {
    double l = 0, r = (n >= 1) ? n : 1;
    while (l + eps < r) {
        double mid = (l + r) / 2;
        if (mid * mid > n + eps) {
            r = mid;
        } else if (mid * mid + eps < n) {
            l = mid;
        } else /* mid * mid == n */ {
            return mid;
        }
    }
}

int binary_search_lowerbound(const vector<int>& a, int key) {
    int res = a.size();
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= key) {
            res = mid;
            r = mid - 1;
        } else /* if (a[mid] < key) */ {
            l = mid + 1;
        }
    }
    return res;
}

// upperbound(x) = position of first element y such that y > x
int binary_search_upperbound(const vector<int>& a, int key) {
    int res = a.size();
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] > key) {
            res = mid;
            r = mid - 1;
        } else /* if (a[mid] < key) */ {
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



string dec_to_bin(int n) {
    string ret = "";
    for (int i = 31; i >= 0; i--) {
        int k = 1 << i;
        ret += (n & k)? '1' : '0';
    }
    int i=0;
    while(ret[i]=='0') i++;
    ret=ret.substr(i);
    return ret;
  
}

ll bin_to_dec(string s){
    ll ans=0;
    for(int i=0;i<s.size();i++){
        ans*=2;
        ans+=s[i]-'0';
    }
    int i=0;
    return ans;
}



int convert(int n) { // binary
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

bool is_bipartite(const vector<vector<int>> &adj){
    vector<int> color(adj.size(),-1);
    queue<int> q;
    color[0]=0, q.push(0);

    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(color[v]==color[u]) return false;
            if(color[v]!=-1) continue;
            color[v]=color[u]^1;
            q.push(v);
        }
    }

}
