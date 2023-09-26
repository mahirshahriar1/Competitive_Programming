#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

vector<bool> isPrime;
void sieve(){
    isPrime.assign(1000001,true);
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i*i<=1000000;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<=1000000;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    
    sieve();
    int n;
    while(cin>>n){
        string s=to_string(n);
        string rs=s;
        reverse(rs.begin(),rs.end());
        cout<<2*n<<endl;
        if(s==rs && isPrime[n]) break;
    }


    return 0;
}