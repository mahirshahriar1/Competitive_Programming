#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n;
    cin>>n;
 
        vector<int> a(n);
        vector<int> b(n);
        vector<pair<int,int>> arr(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
            cin>>b[i];            
            arr[i]={a[i],b[i]};
        }
        int mx=*max_element(range(b));
        int mn=*min_element(range(a));
      

        for(int i=0;i<n;i++){
            if(arr[i].first<=mn and arr[i].second>=mx){                
                cout<<i+1<<endl;
                return 0;
            }
        }
        cout<<-1<<endl;

    

    return 0;
}
