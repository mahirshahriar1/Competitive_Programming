#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


vector <int> primes;
int counter[(int)1e7+1]={0};
int element[(int)1e7+1]={0};
int isprime[(int)1e7+1]={0};
int val=1;

void sieve() 
{     
    isprime[0]=isprime[1]=1;   
    primes.push_back(2);     
    for(int i=3; i<=1e7; i+=2)
    {
        if(isprime[i]==0)
        {
            primes.push_back(i);
            ++val;
            for(int j=i;j<=1e7;j+=i)
            {
                isprime[j]=1;   
                if(element[j]>0)
                {
                    counter[val]+=element[j];
                }
            }
            
        }
    }


}


int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif

    int n,m;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        element[x]++;
        if(x%2==0)
            counter[1]++;        
    }
    
    sieve();   

    for(int i=1;i<=val+1;i++)
        counter[i]+=counter[i-1];
    
    
    cin>>m;    
    while(m--)
    {
        int l,r;
        cin>>l>>r;

        int r_end=upper_bound(primes.begin(),primes.end(),r)-primes.begin();
        int l_end=lower_bound(primes.begin(),primes.end(),l)-primes.begin();

        //this works because counter is 1 based index and primes is 0 based
        /* int r_end=lower_bound(primes.begin(),primes.end(),r)-primes.begin();
            if(primes[r_end]==r)
                 r_end++;
        */
        //cout<<l_end<<' '<<r_end<<endl;

        cout<<counter[r_end]-counter[l_end]<<endl;

    }     
    



    return 0;
}
