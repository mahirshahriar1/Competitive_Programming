#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;


void solve()
{
    int n,k;
    cin>>n>>k;
    
    int odd_remain=n-(k-1);
    bool found=false;
    vector<int> ans;
    if(odd_remain>0&&odd_remain%2){
        for(int i=0;i<k-1;i++)
            ans.push_back(1);
        ans.push_back(odd_remain);
        found=true;
    }
    if(!found){
        int even_remain=n-2*(k-1);

        if(even_remain>0&&even_remain%2==0){
            for(int i=0;i<k-1;i++)
                ans.push_back(2);
            ans.push_back(even_remain);
            found=true;       
        }
    }
    if(!found)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        print(ans);
    }

}

int main()
{
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
