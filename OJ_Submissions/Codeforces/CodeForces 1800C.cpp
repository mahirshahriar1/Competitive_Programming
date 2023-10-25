#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll test;
    cin >> test;

    for (ll testt = 1; testt <= test; testt++)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        priority_queue<ll> pq;
        for(auto &x:v){
            cin>>x;          
        }
        
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(v[i]!=0)
                pq.push(v[i]);
            else if(v[i]==0){
                if(!pq.empty()){
                    ans+=pq.top();                   
                    pq.pop();
                }               
            }
        }
        cout<<ans<<endl;        

    }
}
