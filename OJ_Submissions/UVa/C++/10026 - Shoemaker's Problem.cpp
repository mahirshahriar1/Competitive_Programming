#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;

struct Job{
    int time;
    int fine;
    int index;
};

bool comp(Job a, Job b)
{
    if(a.time * b.fine == b.time * a.fine)
        return a.index < b.index;
    return a.time * b.fine < b.time * a.fine;
} 

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int test;
    cin>>test;
    bool flag=false;
    while(test--){
        if(flag) cout<<endl;
        
        int n;
        cin>>n;
        vector<Job> v;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b,i+1});
        }
        sort(range(v),comp); //if you use stable_sort then no need to handle line 24 and 25
        
        for(int i=0;i<n;i++){
            if(i==n-1){
                cout<<v[i].index;
                break;
            }
            cout<<v[i].index<<" ";
        }
        cout<<endl;
        flag=true;        
    }
}

