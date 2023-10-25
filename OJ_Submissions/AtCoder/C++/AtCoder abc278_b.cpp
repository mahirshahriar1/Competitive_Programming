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


bool isvalid(string a, string b){ 
    string c;
    if(b.size()==1){
        c="0";
    }
    c+=b;
    if(a.size()==2)
        swap(a[1],c[0]);
    else{
        swap(a[0],c[0]);
    }    
    return (stoi(a)<24 and stoi(c)<60);
}

int main(){

    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    string hr,mn;
    cin>>hr>>mn;

    while(!isvalid(hr,mn)){   
        int a=stoi(hr);
        int b=stoi(mn);
        b++;
        mn=to_string(b);
        if(b>59){            
            b=0;
            mn=to_string(b);      
            a++;  
            hr=to_string(a);         
        }
        if(a>23){            
            a=0;
            hr=to_string(a);
        }      
    }   
    
    cout<<hr<<' '<<mn<<endl;


    return 0;

}
