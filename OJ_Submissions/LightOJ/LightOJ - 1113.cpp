#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
 
int kas=0;

void solve()
{    
    cout<<"Case "<<++kas<<":"<<endl;

    stack <string> forward, back;
    string s;
    string tmp="http://www.lightoj.com/";
    forward.push(tmp);
    while(cin>>s, s!="QUIT")
    {
        if(s=="BACK")
        {
            if(back.empty()){
                cout<<"Ignored"<<endl;
            }
            else{
                forward.push(back.top());  
                back.pop(); 
                cout<<forward.top()<<endl;                            
            }
        }
        else if(s=="FORWARD")
        {
            if(forward.empty()){
                cout<<"Ignored"<<endl;
            }
            else{
                back.push(forward.top());
                forward.pop();
                if(forward.empty())
                {
                    cout<<"Ignored"<<endl; 
                    forward.push(back.top());
                    back.pop(); 
                }
                    
                else
                 cout<<forward.top()<<endl;           
            }
        }
        else if(s=="VISIT")
        {            
            string url;     cin>>url;
            if(forward.empty())
                cout<<"Ignored"<<endl;
            else
                back.push(forward.top());

            while(!forward.empty())            
                forward.pop();

            forward.push(url); 
            cout<<forward.top()<<endl;  
        }
    }

  
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
    cin.ignore();
    while(t--)
    {
       solve();
    }
 
    return 0;
}
 
