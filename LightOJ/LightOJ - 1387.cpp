#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int kas=0;


void solve()
{
    int t;
    cin>>t;
    int sum=0;
    cout<<"Case "<<++kas<<":"<<endl;
    while(t--)
    {
        string s;
        int temp;
        cin>>s;    
        if(s=="donate")
        {            
            cin>>temp;
            sum+=temp;
        }
        else
        {
            cout<<sum<<endl;
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

    int t;
    cin>>t;
    while(t--){
        solve();
    }


}
