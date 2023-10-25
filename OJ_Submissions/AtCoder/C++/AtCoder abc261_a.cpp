#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int a,b,c,d;

   cin>>a>>b>>c>>d;

  if(c>=b||(c<a&&d<a))
    cout<<"0"<<endl;
  else if(c>=a&&c<b&&d>=a&&d<=b)
    cout<<d-c<<endl;
  else if (c<a&&(d>=a&&d<=b))
    cout<<d-a<<endl;
  else if(c<b&&c>=a&&d>=b)
    cout<<b-c<<endl;
  else
    cout<<b-a<<endl;
  
  /*int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
 
    int ans = max(0, min(r1, r2) - max(l1, l2));
 
    cout << ans << "\n";*/



   return 0;
}


