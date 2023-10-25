#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


map<ll,ll> dp;

ll solve(ll n){
    if(n==0) return 0;
    if(dp.count(n)) return dp[n];

    ll ans=n;

    ll ans1=solve(n/2)+solve(n/3)+solve(n/4);

    return dp[n]=max(ans,ans1);

}

int main(){

    ll n;
    while(cin>>n){
        cout<<solve(n)<<endl;
    }
    return 0;
}
