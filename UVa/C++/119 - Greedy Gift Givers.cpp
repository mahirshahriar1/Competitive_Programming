#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

int main()
{
    fastio
    #ifndef ONLINE_JUDGE
           freopen("input.txt", "r", stdin);
           freopen("output.txt", "w",stdout);
    #endif

    int n;
    bool flag=false;
    while(cin>>n){
        if(flag)
         cout<<endl;
        map<string,int>mp;
        vector<string> input;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            mp[s]=0;
            input.push_back(s);
        }
        for(int i=0;i<n;i++){
            string s; int amount; int num;
            cin>>s>>amount>>num;
            for(int i=0;i<num;i++){
                string temp; cin>>temp;
                mp[temp]+=amount/num;
                mp[s]-=amount/num;
            }
        }
        for(auto x:input){
            cout<<x<<' '<<mp[x]<<endl;
        }       
        flag=true;
    }


}

