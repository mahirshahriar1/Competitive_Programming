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
#define pb push_back
typedef long long int ll;
const double eps=1e-9;


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n,one=0,two=0;
    cin>>n;
    vector<int> v(n);
    for(auto &x: v){
        cin>>x;
        if(x==1) one++;
        else two++;
    }
    if(one==0||one==n){
        print(v)
    }
    else{
        cout<<"2 1 ";
        two--,one--;
        while(two){
           cout<<2<<' ';
            two--;
        }
         while(one){
           cout<<1<<' ';
            one--;
        }
    }
    cout<<endl;
    return 0;
}
