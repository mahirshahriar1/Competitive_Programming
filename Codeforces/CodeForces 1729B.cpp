#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


string s="0abcdefghijklmnopqrstuvwxyz";

void solve()
{

    int n;
    cin>>n;
    int arr[n];

    string ss;
    cin>>ss;
    ss+="   ";

    for(int i=0;i<n;i++)
    {
        if(ss[i]==' ')
            break;
        if((ss[i+2]=='0')&&(ss[i+3]!='0'))
        {
            int val=(ss[i]-'0')*10+ss[i+1]-'0';
                    cout<<s[val];
             i+=2;
        }
        else{
              cout<<s[ss[i]-'0'];
        }

    }
    cout<<endl;

}


int main()
{
    fastio;

    int t,kas=0;
    cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
