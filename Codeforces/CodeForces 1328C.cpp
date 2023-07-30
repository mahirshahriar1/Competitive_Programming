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

void solve()
{
    int n;
    cin>>n;
    
    string s;
    cin>>s;

    string a(n,'0'), b(n,'0');

    for(int i=0;i<n;i++)
    {        
        if(s[i]=='0')
        {
            a[i]=b[i]='0';
        }
        else if(s[i]=='1'){
                a[i]='1';
                b[i]='0';
                
                for(int j=i+1;j<n;j++){
                    b[j]=s[j];
                }
                break;
        }
        else{
            a[i]=b[i]='1';
        }
    }
   
    cout<<a<<'\n'<<b<<endl;

}

int main()
{
    fastio;
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


}                                          
