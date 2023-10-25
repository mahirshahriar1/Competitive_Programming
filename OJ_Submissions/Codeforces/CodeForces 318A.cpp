#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
typedef long long int ll; 

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    ll n,k;
    cin>>n>>k;

    ll x=(n+1)/2;

    if(k<=x){
        if(k==1){
            cout<<1<<endl;            
        }else{
            ll need=2*(k-1);
            cout<<need+1<<endl;
        }
    }else{
        k-=x;
        cout<<2*k<<endl;        
    }

    return 0;
}
