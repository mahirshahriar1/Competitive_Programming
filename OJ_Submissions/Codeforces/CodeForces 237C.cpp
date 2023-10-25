#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)
#define mod 1000000007
const double eps=1e-9;

vector <int> isprime;
int prefix[(int)1e6+10];

void sieve() 
{
    int n=1e6+1;
    isprime.assign(n+1,1);

    isprime[0]=isprime[1]=0;

    for(int i=2; i*i<=n; i++)
    {
        if(!isprime[i])
            continue;
        for(int j=i*i; j<=n; j+=i)
        {
            isprime[j]=0;
        }
    }
}

void prefix_sum()
{    
    prefix[0]=0;
    for(int i=1;i<=1e6;i++)
        prefix[i]=prefix[i-1]+isprime[i];
}

int a,b,k;

bool ok(int mid)
{
    for(int i=a;i<=b-mid+1;i++)
    {
        if(prefix[i+mid-1]-prefix[i-1]<k)
            return false;
    }
    return true;
}


int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif
    sieve();
    prefix_sum();

    cin>>a>>b>>k;

    int l=1,r=b-a+1,mid,res=-1;

     while(l<=r){
        ll mid = (l+r)>>1;
        if (ok(mid)){
            res=mid;
            r=mid-1;
        }else 
        {
            l=mid+1;
        }
    }
    cout<<res<<endl;
    
 
    return 0;
}
