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



int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif  
    
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i])
            continue;
        int pos=-1;

        for(int j=i+1;j<n;j++)
        {
            if(s[j]==t[i])
            {
                pos=j;
                break;
            }
        }
        if(pos==-1)
        {
            cout<<"-1"<<endl;
            break;
        }
        for(int j=pos-1;j>=i;j--)
        {
            swap(s[j],s[j+1]);
            ans.push_back(j+1);
        }
    
    }
    if(s!=t)
        return 0;
    
    cout<<ans.size()<<endl;
    print(ans);


}                                          
