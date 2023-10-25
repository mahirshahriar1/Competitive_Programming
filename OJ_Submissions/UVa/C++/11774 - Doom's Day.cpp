#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;
    
int GCD(int a, int b)
{
        if(b==0)
            return a;
        return GCD(b,a%b);
} 

int main()
{
    fastio;
    #ifndef ONLINE_JUDGE         
        freopen("input.txt", "r", stdin);        
        freopen("output.txt", "w",stdout);   
    #endif  

   int t,kas=0;
   cin>>t;
   while(t--)
   {
        int m,n;
        cin>>m>>n;
        cout<<"Case "<<++kas<<": ";
        if(m==n)
        {
            cout<<2<<endl;
            continue;
        }
        int gcd=GCD(m,n);
        cout<<m/gcd+n/gcd<<endl;
   }

}
