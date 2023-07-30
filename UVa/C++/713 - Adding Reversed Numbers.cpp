#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;

void omitleadingzeroes(string &s){
    int i=0;
    while(s[i]=='0') i++;
    s=s.substr(i);
}

void addnumbers(string &a,string &b){
    int carry=0;
    string ans="";
    //reverse(range(a));
    //reverse(range(b));
    for(int i=0;i<max(a.size(),b.size());i++){       
        int x=0,y=0;
        if(i<a.size()) x=a[i]-'0';
        if(i<b.size()) y=b[i]-'0';
        int sum=x+y+carry;
        carry=sum/10;
        sum%=10;
        ans+=sum+'0';
    }
    if(carry) ans+=carry+'0';
    //reverse(range(ans));
    omitleadingzeroes(ans);
    cout<<ans<<endl;
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        addnumbers(a,b);
    }
    return 0;

}
