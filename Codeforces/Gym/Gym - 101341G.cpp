#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
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
    string names[n];
    string s="I_love_";
    for(int i=0;i<n;i++){
        cin>>names[i];
    }
    int x;
    cin>>x;
    vector<pair<int,int>> v(x);
    int ind=-1;
    for(int i=0;i<x;i++){
        cin>>v[i].first>>v[i].second;
        if(v[i].first==1){
            ind=i;
        }
    }
    if(ind==-1) {
        cout<<names[0]<<endl;
        return 0;
    }
    //cout<<ind<<endl;
    int cnt(1);
    int val=v[ind].second;
   // cout<<ind<<endl;
    do{
        bool flag=false;
        val=v[ind].second;
        //cout<<v[ind].second<<endl;
        for(int i=ind;i>=0;i--){
            if(v[i].first==v[ind].second){
                ind=i;               
                flag=true;
                //cout<<tofind<<endl;
                cnt++;
                break;
            }
        }
        if(!flag) break;
    } while(true);

    while(cnt--){
        cout<<s;
    }
    cout<<names[val-1]<<endl;


    return 0;
    
}
