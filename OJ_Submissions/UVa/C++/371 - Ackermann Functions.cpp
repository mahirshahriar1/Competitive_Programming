#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

unordered_map<ll,ll> mp;

ll solve(ll n){
    if(n==1) return 0;
    if(mp.find(n)!=mp.end()) return mp[n];
    ll res=0;
    if(n%2==0) 
        res=1+solve(n/2);
    else 
        res=1+solve(3*n+1);
    return mp[n]=res;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
  //brute force will work too :))
    ll l,h;
    while(cin>>l>>h){
        if(l==0 or h==0) break;
        if(l>h) l^=h^=l^=h;
        ll res=0;
        ll output=0;
        for(ll i=l;i<=h;i++){
            ll val=solve(i);           
            if(i==1) val=3;
            if(val>res){
                res=val;
                output=i;
            }
        }
        cout<<"Between "<<l<<" and "<<h<<", "<<output<<" generates the longest sequence of "<<res<<" values."<<endl;    

    }
}