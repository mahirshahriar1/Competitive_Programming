#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)


string decimalToBinary(int n) {
    string bin = "";
    for (int i = 31; i >= 0; i--) {
        int k = 1 << i;
        bin += (n & k)? '1' : '0';
    }
    return bin;
}

int binaryToDecimal(string s) {
    int dec = 0;
    for (int i=0; i<32; i++) 
        dec =(2*dec)+s[i]-'0';
    return dec;
}

int kas=0;

void solve()
{       
    int n;
    cin>>n;

    string bin=decimalToBinary(n);
      
    next_permutation(bin.begin(),bin.end()); 

    cout<<"Case "<<++kas<<": "<<binaryToDecimal(bin)<<endl;    
   
}

int main()
{
    fastio;
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
   
    return 0;
}
 
