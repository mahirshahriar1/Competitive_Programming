#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
typedef long long int ll;
const double eps=1e-9;


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    // vector<char> v={'B','C','G'};
    // //sort(v.begin(),v.end()); //already sorted BGC
    // while(next_permutation(v.begin(),v.end())){
    //     for(auto x:v){
    //         cout<<x<<' ';
    //     }
    //     cout<<'\n';
    // }

    /* 
        B C G
        B G C 
        C B G 
        C G B 
        G B C 
        G C B 
    */

    int b1,g1,c1,b2,g2,c2,b3,g3,c3;

    while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3){
        int ans=INT_MAX;
        string s;
        if(b2+b3+c1+c3+g1+g2<ans){
            ans=b2+b3+c1+c3+g1+g2;
            s="BCG";
        }
        if(b2+b3+g1+g3+c1+c2<ans){
            ans=b2+b3+g1+g3+c1+c2;
            s="BGC";
        }
        if(c2+c3+b1+b3+g1+g2<ans){
            ans=c2+c3+b1+b3+g1+g2;
            s="CBG";
        }
        if(c2+c3+g1+g3+b1+b2<ans){
            ans=c2+c3+g1+g3+b1+b2;
            s="CGB";
        }
        if(g2+g3+b1+b3+c1+c2<ans){
            ans=g2+g3+b1+b3+c1+c2;
            s="GBC";
        }
        if(g2+g3+c1+c3+b1+b2<ans){
            ans=g2+g3+c1+c3+b1+b2;
            s="GCB";
        }
        cout<<s<<' '<<ans<<'\n';
    }


    return 0;

}
