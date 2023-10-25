#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;
 

int main()
{
    #ifndef ONLINE_JUDGE  
            freopen("input.txt", "r", stdin); 
            freopen("output.txt", "w",stdout);
    #endif   
   
    string s[] = {"monday", "tuesday", "wednesday", "thursday", 
                  "friday","saturday","sunday"};

    string in1,in2;
    cin>>in1>>in2;

    int x,y;
    for(int i=0;i<7;i++)
    {
        if(in1==s[i])
        {
            x=i;
        }
        if(in2==s[i])
        {
            y=i;
        }
    }

    if((x+28)%7==y||(x+30)%7==y||(x+31)%7==y)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
   
    return 0;
}
