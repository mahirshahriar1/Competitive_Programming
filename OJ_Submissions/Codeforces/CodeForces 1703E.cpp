#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    cin.ignore();
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        for(int j=0;j<n;j++){
            matrix[i][j]=s[j]-'0';
        }
    }   

    auto rotate90=[&](int& x,int& y){
        int tmp=x;
        x=y;
        y=n-1-tmp;
    };

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp1=0,tmp0=0;
            int x=i,y=j;
            for(int k=0;k<4;k++){
                rotate90(x,y);               
                matrix[x][y]==1?tmp1++:tmp0++;
            }                        
            cnt+=min(tmp1,tmp0);
        }
    }   
    cout<<cnt/4<<endl;

}

int main(){
    fastio  
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
