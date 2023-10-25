#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)
#define mod 1000000007
const double eps=1e-9;

ll factorial[21];

void precompute()
{
    factorial[0]=1;
    for(int i=1;i<=20;i++)
        factorial[i]=i*factorial[i-1];    
}


int kas=0;

void solve()
{
    cout<<"Case "<<++kas<<": ";

    ll s,row,column;
    cin>>s;

    ll root=ceil(sqrt(s));
    ll diff=root*root-s;

    if(diff<root){
        row=root;
        column=diff+1;
    }
    else{
        column=root;
        row=s-pow(root-1,2);    
    }
    if(root%2==0){
        swap(row,column);
    }
    cout<<column<<' '<<row<<endl;
   

}

int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif
    precompute();

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
