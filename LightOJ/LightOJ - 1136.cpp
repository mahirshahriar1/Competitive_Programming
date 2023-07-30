#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl "\n"
#define ll long long
#define cfaster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


ll no_div_by_3_from_1_to_n(ll n)
{
    if(n==0)
        return 0;
    if(n%3==0)
        return n-n/3;
    else 
        return n-(n/3+1);
}

int main()
{
    cfaster;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif  
    
    int t,kas=0;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;

        cout<<"Case "<<++kas<<": "<<no_div_by_3_from_1_to_n(b)-no_div_by_3_from_1_to_n(a-1)<<endl;

    }

    return 0;
}                                          
