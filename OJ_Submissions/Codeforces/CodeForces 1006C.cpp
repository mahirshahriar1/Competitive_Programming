#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int

int main(){
    fastio
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto & x:v){
        cin>>x;
    }
    int l=0,r=n-1;
    ll sum1,sum2,sum3,mx;
    sum1=sum2=sum3=mx=0;
    
    while(l<=r){
        if(sum3<sum1){
            //cout<<v[r]<<endl;
            sum3+=v[r--];
        }else{
            //cout<<v[l]<<endl;
            sum1+=v[l++];
        }
        if(sum1==sum3){
            mx=max(sum1,mx);
        }
    }
    cout<<mx<<endl;
    return 0;

}
