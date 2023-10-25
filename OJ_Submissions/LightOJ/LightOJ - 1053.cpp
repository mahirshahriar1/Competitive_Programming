#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int kas=0;


void solve()
{
    int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    
    sort(arr,arr+3);

    if(pow(arr[2],2)==(pow(arr[1],2)+pow(arr[0],2)))
        cout<<"Case "<<++kas<<": yes"<<endl;
    else
        cout<<"Case "<<++kas<<": no"<<endl;

}


int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }


}
