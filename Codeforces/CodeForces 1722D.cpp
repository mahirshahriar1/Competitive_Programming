#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 998244353

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

vector <bool> isprime;
vector <int> primes;

void solve()
{
    int n;
    string s;
    cin>>n>>s;
    deque<int> L,R;
    ll sum=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='L'){
            L.push_back(i);
            sum+=i;
        }else{
            R.push_back(i);
            sum+=n-i-1;
        }
    }
    ll arr[n];
    for(int i=0;i<n;i++){
        ll val1=0,val2=0;
        if(!L.empty()) val1=sum-L.front()+n-L.front()-1;
        if(!R.empty()) val2=sum-(n-R.back()-1)+R.back();

        if(val1>val2){
            sum=max(sum,val1);
            L.pop_front();
        }else{
            sum=max(sum,val2);
            R.pop_back();
        }
        arr[i]=sum;
    }

    print(arr);


}

int main()
{
    fastio
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
/*

#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


int main()
{
    fastio;
    int t;
    cin>>t;

    while(t--)
    {
        ll n;        cin>>n;
        string s;    cin>>s;
        ll sum=0;

        vector<ll>v;

        for(ll i=0; i<n; i++)
        {
            if(s[i]=='L')
            {
                ll val=i;
                ll change=n-(i+1);
                v.push_back(change-val);

                sum+=i;
            }

            else
            {
                ll val=n-(i+1);
                ll change=i;
                v.push_back(change-val);

                sum+=n-(i+1);
            }

        }

       sort(v.begin(),v.end());

       for(ll i=0; i<n; i++)
        {
            ll change=v.back();
            v.pop_back();

            if(change>0)
                sum+=change;
            cout<<sum<<" ";

        }
        cout<<endl;

    }


    return 0;
}*/
