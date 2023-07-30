#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;



int kas=0;       
void solve()
{
    string s1;
    cin>>s1;
    string s2=s1;
    reverse(s2.begin(),s2.end());

    if(s1==s2)  cout<<"Case "<<++kas<<": Yes"<<endl;
    else        cout<<"Case "<<++kas<<": No"<<endl;

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
    while(t--)
    {
        solve();
    }  



}
