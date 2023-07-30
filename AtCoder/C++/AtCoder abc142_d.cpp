#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define endl '\n'

bool isprime(ll n){
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

map<ll,int> mp; 

void divisors(ll n) {
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            mp[i]++;
            if (n / i != i) {
                mp[n/i]++;
            }
        }
    }

}

int main()
{   
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
   ll a,b;
   cin>>a>>b;
   if(__gcd(a,b)==1){
    cout<<1<<endl;
    return 0;
   }

   divisors(a);
   divisors(b);
   vector<ll>ans;
    for(auto x:mp){
        if(x.second==2){
            ans.push_back(x.first);
        }
    }
    int cnt=0;
    for(auto x:ans){
        if(isprime(x)){              
            cnt++;
        }
    }

    cout<<cnt<<endl;

}
