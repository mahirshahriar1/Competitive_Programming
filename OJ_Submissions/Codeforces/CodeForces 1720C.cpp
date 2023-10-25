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

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];

    int sum=0;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
           arr[i][j]=s[j]-'0'; 
           if(arr[i][j]==1)
                sum++;
        }               
    }

    if(sum==0){
        cout<<0<<endl;
        return;
    }
    int mn=INT_MAX;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            int temp=arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i][j+1];
            if(temp==0)   continue;
            mn=min(mn,temp);
        }
    }
    if(mn<3){
        cout<<sum<<endl;
    }else{
        cout<<sum-mn+2<<endl;
    }

}

int main(){
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
    return 0;
}
