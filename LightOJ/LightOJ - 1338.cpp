#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;



int kas=0;       
void solve()
{      
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    s1.erase(remove(s1.begin(),s1.end(),' '),s1.end());
    s2.erase(remove(s2.begin(),s2.end(),' '),s2.end());

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    
    cout<<"Case "<<++kas<<": "<<(s1==s2?"Yes":"No")<<endl;

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
    cin.ignore();
    while(t--)
    {
        solve();
    }  



}
