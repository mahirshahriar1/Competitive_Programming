#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const int n=1e6+2;
const int m=1e6+2;

vector <bool> isprime;
vector <int> primes;


void sieve(int n) //prime
{
    isprime.assign(n+1,true);

    isprime[0]=isprime[1]=false;

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

} 

int count_pfactor(int n) 
{
    int size=sqrt(n) , count(0);
    for(int i=0;primes[i]<=size&&i<primes.size();i++)
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

    int arr[m+2],ans[11][m+2];

int main()
{
    fastio;

    sieve(n);


    arr[1]=0;
    for(int i=2;i<m;i++)
    {
        if(!isprime[i])
            arr[i]=count_pfactor(i);
        else 
          arr[i]=1;
    }

    for(int i=0;i<11;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(arr[j]==i)
                cnt++;

            ans[i][j]+=cnt;
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;        
        cout<<ans[c][b]-ans[c][a-1]<<endl;
    } 


    return 0;
}
