#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define endl '\n'



int main()
{    
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(auto& x:v){
        cin>>x;
    }
    sort(v.begin(),v.end());
//    for(auto x: v) cout<<x<< ' ';
//    cout<<endl;
    int cnt=0;
    for(int i=0;i<n;i++) {
        int ind=upper_bound(v.begin()+i,v.end(),v[i])-v.begin();
        //cout<<v[i]<<' '<<ind<<endl;
        cnt+=n-ind;
    }
    cout<<cnt<<endl;



}
