#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define range(v) v.begin(),v.end()
typedef long long int ll;

int dot1,dot2,hash1,hash2;

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n,m;
    cin>>n>>m;
     
    char x;
    vector<int> arr1,arr2,arr3,arr4;
    for(int i=0;i<n;i++){
        dot1=hash1=0;
        for(int j=0;j<m;j++){
            cin>>x;
            if(x=='.') dot1++;
            else hash1++;
        }
        arr1.push_back(dot1);
        arr2.push_back(hash1);
    }

     for(int i=0;i<n;i++){
         dot2=hash2=0;
        for(int j=0;j<m;j++){
            cin>>x;
            if(x=='.') dot2++;
            else hash2++;
        }
        arr3.push_back(dot2);
        arr4.push_back(hash2);
    }
    
    bool flag=true;

    for(int i=0;i<n;i++){
        if(arr1[i]!=arr3[i]){
            flag=false;
            break;
        }
        if(arr2[i]!=arr4[i]){
            flag=false;
            break;
        }
    }

    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}
