#include <bits/stdc++.h>
using namespace std;
#define endl '\n';


int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    while(cin>>n){
        vector<int> v(n);
        for(auto &x:v) cin>>x;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]>v[j]){  
                    cnt++;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<cnt<<endl;
    }
    return 0;
}