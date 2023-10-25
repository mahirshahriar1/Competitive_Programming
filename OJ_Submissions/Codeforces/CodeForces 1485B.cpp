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

int main()
{   
    fastio  
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
     #endif
    
   int n,q,k;
   cin>>n>>q>>k;

   vector<int> v(n+1,0);
   for(int i=1;i<=n;i++){
        cin>>v[i];
   }

   vector<ll> summ(n+1,0);
   summ[1]=v[2]-2;   
   for(int i=2;i+1<=n;i++){
       summ[i]=v[i+1]-v[i-1]-2;
   }
   summ[n]=k-v[n-1]-1;
    //print(summ)

    for(int i=1;i<=n;i++){
        summ[i] += summ[i-1];
    }
     //print(summ)

    while (q--) {
        int l, r;
        cin>>l>>r;
        ll ways = 0;
        if(r-l==1){
            ways= (k-v[r-1]-1)+(v[l+1]-2);  //only edges
        }else if(l==r){
            ways=k-1;
        }else{
            ways=summ[r-1]-summ[l];  //excluding edges
            ways += (k-v[r-1]-1) +(v[l+1]-2);
        }
        cout<<ways<<endl;
    } 

}
