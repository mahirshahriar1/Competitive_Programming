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


int module(string num, int mod)
{
    int i=0;
    if(num[0]=='-')
        i=1;

    int res=0;
    for( ;i<num.size();i++)
    {
        int d=num[i]-'0';
        res=(res*10)+d;
        res%=mod;
    }
    if(num[0]=='-')
        return -res;
    else
        return res;
}

int main(){
  fastio  
  #ifndef ONLINE_JUDGE  
         freopen("input.txt", "r", stdin); 
         freopen("output.txt", "w",stdout);
  #endif

  string s;
  while(cin>>s)
  {
      if(s=="0")
        break;
      int n=module(s,11);
      if(n==0)
        cout<<s<<" is a multiple of 11."<<endl;
      else
        cout<<s<<" is not a multiple of 11."<<endl;
  }
}
