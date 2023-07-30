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


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif


    int T;
    cin>>T;
    bool flag=false;
    while(T--){
        if(flag) cout<<endl;
        vector<string> words;
        string word;
        while(cin>>word,word!="*"){
            words.push_back(word);
        }

        cin.ignore();
        string line;
        while(getline(cin,line),line!=""){
            stringstream ss(line);
            string s,t;
            ss>>s>>t;
            
            queue<string> q;
            map<string,int> dist;
            q.push(s);
            dist[s]=0;

            while(!q.empty() and !dist.count(t)){
                string u=q.front();
                q.pop();
                for(auto w:words){
                    if(w.size()==u.size() and !dist.count(w)){
                        int diff=0;
                        for(int i=0;i<w.size();i++){
                            if(w[i]!=u[i]) diff++;
                        }
                        if(diff==1){
                            q.push(w);
                            dist[w]=dist[u]+1;
                        }
                    }
                }

            }
            cout<<s<<" "<<t<<" "<<dist[t]<<endl;

        }

        flag=true;
    }


    return 0;
}
