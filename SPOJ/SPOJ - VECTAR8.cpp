#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;
    
vector <bool> isprime;

void sieve(int n) 
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
}

vector<int> ans((int)1e6+5,0);
void prefixSum()
{   
    ans[2]=1;
    for(int i=3;i<=1e6;i++)
    {
        if(isprime[i]){
            int temp=i, base=1, num=0;
            bool afraid=true;
            while(temp){            
                if(temp%10==0){                    
                    afraid=false;
                    break;
                }
                num=(base*(temp%10))+num;               
                if(!isprime[num]){
                    afraid=false;
                    break;
                }              
                 base*=10, temp/=10;
            }

            if(!afraid)
            {
                ans[i]+=ans[i-1];
                //cout<<"not afraid "<<i<<endl;
            }
                
            else
            { 
                ans[i]=ans[i-1]+1;
                //cout<<"afraid "<<i<<endl;
            }
               

        }else{
            ans[i]+=ans[i-1];
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

    
    sieve(1e6);
    prefixSum();

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }

}
    
