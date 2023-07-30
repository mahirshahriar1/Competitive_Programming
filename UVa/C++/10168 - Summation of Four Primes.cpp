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


vector <bool> isPrime;
void sieve(int n){
    isPrime.assign(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

void printOtherTwo(int n){
  for(int i=2;i<=n;i++){
    if(isPrime[i] && isPrime[n-i]){
      cout<<i<<' '<<n-i<<endl;
      return;
    }
  }
}

int main(){
  fastio  
  #ifndef ONLINE_JUDGE  
         freopen("input.txt", "r", stdin); 
         freopen("output.txt", "w",stdout);
  #endif

  sieve(10000000);
  int n;
  while(cin>>n){
    if(n<8){
      cout<<"Impossible."<<endl;
      continue;
    }
    //cout<<n<<" = ";
    if(n%2==0){
      cout<<2<<' '<<2<<' ';
      printOtherTwo(n-4);
    }else{
      cout<<2<<' '<<3<<' ';
      printOtherTwo(n-5);
    }
  }
}
