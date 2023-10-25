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

const int N=2;

void rotate90Clockwise(int a[N][N])
{   
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) { 
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

bool check(const int arr[N][N]){
    if(arr[0][1]>arr[0][0] or arr[1][1]>arr[1][0]){
        return false;
    }else if(arr[0][0]>arr[1][0] or arr[0][1]>arr[1][1]){
        return false;
    }
    return true;
}

void solve(){    
    int arr[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    int t=4;
    while(t--){
        if(check(arr)) {
            cout<<"YES"<<endl;
            return;
        }
        else{
            rotate90Clockwise(arr);
        }
    }
    cout<<"NO"<<endl;

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
