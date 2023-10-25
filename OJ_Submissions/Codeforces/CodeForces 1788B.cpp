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

// ll getFirstDigit(ll n){
//     while(n>=10){
//         n/=10;
//     }
//     return n;
// }
// ll sumOfdigits(ll n){
//     ll sum=0;
//     while(n){
//         sum+=n%10;
//         n/=10;
//     }
//     return sum;
// }

void omitLeadingZeroes(string &s){
    reverse(range(s));
    int i=0;
    while(s[i]=='0' and i<s.size()-1){
        i++;
    }
    s=s.substr(i);
}

void solve(){
    ll n;
    cin>>n;
    string a="",b="";
 
    int cnt=0;
    while(n){
        int digit=n%10;
        int val=digit/2;
        if(digit%2==0){
            a+=to_string(val);
            b+=to_string(val);
        }else{k
            if(cnt%2){
                a+=to_string(val);
                b+=to_string(val+1);
            }else{
                a+=to_string(val+1);
                b+=to_string(val);
            }
            cnt++;
        }   
        n/=10;
    }
    omitLeadingZeroes(a);
    omitLeadingZeroes(b);

    cout<<a<<" "<<b<<endl;
    
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
       solve();
    }
    return 0;
}
