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

    int kas=0;
    stack<char> empty;
    vector<stack<char>> containers;
    string str;
    
    while(cin>>str, str!="end"){
        containers.clear();

        int ans=0;

        for(int i=0;i<str.size();i++){
            bool found=false;
            for(int j=0;j<containers.size();j++){
                if(str[i]<=containers[j].top()){
                    containers[j].push(str[i]);
                    found=true;
                    break;
                }
            }
            if(!found){
                containers.push_back(empty);
                containers.back().push(str[i]);
                ans++;
            }
        }        

        cout<<"Case "<<++kas<<": "<<ans<<endl;
    }

    return 0;

}
