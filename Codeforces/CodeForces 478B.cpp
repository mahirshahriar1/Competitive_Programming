#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


void solve()
{
    ll n,m;
    cin>>n>>m;
    
    ll mx=((n-m+1)*(n-m))/2; 
    
    ll val=n/m;  
    ll rem=n%m;
    ll mn= (rem*((val+1)*val)/2)+((m-rem)*((val)*(val-1))/2); // 5 3 -> min -> 2 2 1  (2 group minimum)  6 3-> min -> 2 2 2  (3 group minimum)
    
    cout<<mn<<' '<<mx<<endl;

}


int main()
{
    fastio;

    solve();

    return 0;
}
