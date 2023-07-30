#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int kas=0;


int convert(int n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}



void solve()
{
    int a,b,c,d,e,f,g,h;

    scanf("%d.%d.%d.%d",&a,&b,&c,&d);
    scanf("%d.%d.%d.%d",&e,&f,&g,&h);

    e=convert(e);
    f=convert(f);
    g=convert(g);
    h=convert(h);
   
    if(a==e&&b==f&&c==g&&d==h)
        cout<<"Case "<<++kas<<": Yes"<<endl;
    else
        cout<<"Case "<<++kas<<": No"<<endl;

}


int main()
{
    //fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif
 
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }


}
