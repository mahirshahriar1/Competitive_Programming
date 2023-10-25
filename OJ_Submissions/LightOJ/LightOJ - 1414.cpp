#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)

int kas=0;

void solve()
{       
    string m1,m2;
    int d1,d2,y1,y2;
    char c;
    cin>>m1>>d1>>c>>y1;
    cin>>m2>>d2>>c>>y2;

    if(!(m1=="January"||m1=="February"))
        y1++;
    if(m2=="January"||(m2=="February"&&d2<29))
        y2--;
    
    int ans=(y2/4-(y1-1)/4)+(y2/400-(y1-1)/400)-(y2/100-(y1-1)/100);
  
    cout<<"Case "<<++kas<<": "<<ans<<endl;
   
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
    cin.ignore();
    while(t--)
    {
       solve();
    }
   
    return 0;
}
 
