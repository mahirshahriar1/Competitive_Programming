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

    int n;
    cin>>n;
    string s;
    cin>>s;

    string ans="";
    for(int i=0;i<n;i++){
             if(s[i]=='2') ans+="2";
        else if(s[i]=='3') ans+="3";
        else if(s[i]=='4') ans+="322"; //4!= 3!*4 =  3!*2!*2!
        else if(s[i]=='5') ans+="5";
        else if(s[i]=='6') ans+="53"; //6!= 5!*6=5!*3! (3*2*1=6!)
        else if(s[i]=='7') ans+="7";
        else if(s[i]=='8') ans+="7222";  //8! = 7!*8
        else if(s[i]=='9') ans+="7332";  //8!*9 = 7!*8*9 (3*2) (3*2) (2)
    }
    sort(range(ans));
    reverse(range(ans));
    cout<<ans<<endl;

}

