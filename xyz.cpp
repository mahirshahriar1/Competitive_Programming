#if defined LOCAL && !defined ONLINE_JUDGE
#include "debug.cpp"
#else 
#include <bits/stdc++.h>
using namespace std;
#define dbg(...);
#endif

typedef long long int ll;

#define endl '\n'
#define all(v) v.begin(), v.end()
#define print(v) for(auto& i:v) cout<<i<<" "; cout<<endl;
#define len(v) (int)v.size()

template<typename T>
inline void operator>>(istream& istream, vector<T>& v){for (T& i : v) {cin >> i;}}

#define cerr if(false)cerr

void solve()
{
   
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1, tc = 0;
    cin >> t;
    while (t--)
    {
        cerr << "Case #" << ++tc << ": \n";
        solve();
        cerr << endl;
    }

    return 0;
}

//-------------------------------------


/* Sliding Window Maximum  */
void subarray()
{
    int n,k;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;

    deque <int> dq;

    int i=0;
    for(;i<k;i++)
    {
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for(;i<n;i++)
    {
       cout<<arr[dq.front()]<<' ';

        while(!dq.empty()&&dq.front()<=(i-k))
            dq.pop_front();

        while(!dq.empty()&&arr[i]>=arr[dq.back()])
            dq.pop_back();
       dq.push_back(i);

    }
    cout<<arr[dq.front()]<<' ';
    cout<<endl;

}

bool isBalanced(string s){	
    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk.push(s[i]);
        else{
            if(stk.empty())
                return false;  
            else if(s[i]==')'&&stk.top()!='(')                
                return false; 
            else if(s[i]==']'&&stk.top()!='[')
                return false; 
            else if(s[i]=='}'&&stk.top()!='{')
              	return false; 
            stk.pop();
        }
    }
    if(stk.empty())
        return true;
    return false;
}

/* substring occurence  dynamic programming dp */
int count(string a, string b)
{
    int m = a.length();
    int n = b.length();
 
    int lookup[m + 1][n + 1] = { { 0 } };
 
    for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;
 
    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1]%mod +
                               lookup[i - 1][j]%mod;
                 
            else
                lookup[i][j] = lookup[i - 1][j]%mod;
        }
    }
 
    return lookup[m][n]%mod;
}

/* string techniques */
//  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
//  s2.erase(remove(s2.begin(),s2.end(),' '),s2.end());
//  lower case erase

----------------------------------------------
/* length of greatest subarray with a given sum */
    sum=0;
        int l=0,res=-1;
        for (int r = 0; r < n; ++r){
            sum += v[r];
            while (sum > k){
                sum -= v[l];
                l++;
            }
            if (sum == k)
                res = max(res, r - l + 1);
        }
----------------------------------------------
    /* minimal subarray length which has sum greater than s */
for(int i=0;i<n;i++){
            sum+=v[i];
            while(sum>=s){                
                ans=min(ans,i+1-ind);                
                flag=true;
                sum-=v[ind++];         
            }
        }  
----------------------------------------------

/* for a given array, all possible combination */
for(int i=0;i<(1<<arr.size());i++){
        cnt=0;
        for(int j=0;j<arr.size();j++){
            if(i&(1<<j)){
                cout<<arr[j]<<endl;
                cnt++;
            }
        }  
    }
----------------------------------------------

/* Largest Sum Contiguous Subarray (Kadane’s Algorithm) */
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

    
struct Point {
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
    int val = (p2.y - p1.y) * (p3.x - p2.x)
              - (p2.x - p1.x) * (p3.y - p2.y);
 
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





//GRAPH CYCLE PRINT
int start=-1, stop=-1;
void dfs(int u, int p, vector<int>& color, vector<int>& parent)
{
    // cout<<u<<" "<<p<<endl;
    if(color[u] == 2)
        return;

    if(color[u] == 1){
        start = u;
        stop = p;
        return;
    }

    parent[u] = p;
    color[u] = 1;
    for(int v: adj[u])
    {       
        // if(v == parent[u]) 
        //     continue; //??????
        dfs(v, u, color, parent);
        if(start != -1)
            return;
    }
    color[u] = 2;
}
 vector<int> color(n+1, 0), parent(n+1, -1);
    start = -1;
    stop = -1;
    for(int i=1; i<=n; i++)
    {
        if(color[i]==0)
        {
            dfs(i, -1, color, parent);
            if(start != -1) 
                break;
        }
    }      
 
    vector<int> arr;
    arr.push_back(start);
    for(int i=stop; i!=start; i=parent[i])
    {
        arr.push_back(i);
    }
    //arr.push_back(start);
    reverse(range(arr));
    ------------------

