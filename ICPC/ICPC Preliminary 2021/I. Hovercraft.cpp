#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const double eps = 1e-9;

int main(){
    fastio  
    
    int l,w;
    while(cin>>l>>w, l!=0){
        double ans = w+0.75*l;
        cout<<fixed<<setprecision(4)<<ans<<endl;
    }

}
