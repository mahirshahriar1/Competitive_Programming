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
#define pb push_back
typedef long long int ll;
const double eps=1e-9;

void solve()
{

}

int main()
{
    fastio
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string> words,brackets;
    bool start=false,bracket=false;
    int mx1=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){

            string temp="";
            while(s[i]!=')'){
                if(isalpha(s[i])){
                    start=true;
                    temp+=s[i];
                }
                if(start&&(s[i+1]=='_'||s[i+1]==')')){
                    start=false;
                    words.pb(temp);
                    temp="";
                }

                i++;
            }
            start=false;
            continue;
        }
         if(isalpha(s[i])){
            int cnt=0;
            while(i<n){
                if(!isalpha(s[i]))
                    break;
                else cnt++;
                i++;
            }
            i--;
            mx1=max(mx1,cnt);
            cnt=0;
        }
    }
    cout<<mx1<<' '<<words.size()<<endl;


    return 0;
}
