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

void solve(){
    int n,q;
    cin>>n>>q;
    deque<int>v(n);
    vector<int> ind(n + 1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        ind[v[i]]=i;
    }
    int winner=max_element(range(v))-v.begin();
    vector<vector<int>> wins(n,vector<int>());
    for(int i=1;i<=n;i++){
        int x=v[0],y=v[1];
        if(y>x) swap(x,y);
    
        wins[ind[x]].push_back(i);

        v.pop_front(), v.pop_front();       
        v.push_front(x), v.push_back(y);
    }
    while(q--){
        int i,k;
        cin>>i>>k;
        i--;
        int itr=upper_bound(range(wins[i]),k)-wins[i].begin();
        if(i==winner){          
            if(k<=wins[i].back()){
                cout<<itr<<endl;
            }else{
                cout<<k-wins[i].front()+1<<endl;
            }
        }else{
            cout<<itr<<endl;
        }

    }
    
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }
}
