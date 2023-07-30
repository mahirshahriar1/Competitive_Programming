//https://codeforces.com/gym/390737/problem/C

#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

    string s,x="",y="";
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        x+=s[0];
        y+=s[0]+1;
    }

    if(stoll(x)>=stoll(s))
        cout<<x<<endl;
    else
        cout<<y<<endl;



   return 0;
}


