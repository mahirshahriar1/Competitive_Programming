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


string multiplication(string s1,string s2){
    int n1=s1.size();
    int n2=s2.size();
    if(n1==0 || n2==0) return "0";
    vector<int> result(n1+n2,0);
    int i_n1=0;
    int i_n2=0;
    for(int i=n1-1;i>=0;i--){
        int carry=0;
        int n1=s1[i]-'0';
        i_n2=0;
        for(int j=n2-1;j>=0;j--){
            int n2=s2[j]-'0';
            int sum=n1*n2+result[i_n1+i_n2]+carry;
            carry=sum/10;
            result[i_n1+i_n2]=sum%10;
            i_n2++;
        }
        if(carry>0){
            result[i_n1+i_n2]+=carry;
        }
        i_n1++;
    }
    int i=result.size()-1;
    while(i>=0 && result[i]==0){
        i--;
    }
    if(i==-1) return "0";
    string s="";
    while(i>=0){
        s+=to_string(result[i--]);
    }
    return s;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    
    string a,b;
    while(cin>>a>>b){
        cout<<multiplication(a,b)<<endl;
    }
  
}
