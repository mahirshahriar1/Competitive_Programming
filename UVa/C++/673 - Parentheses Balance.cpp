#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)



int main()
{
    fastio;

     ll t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        stack<char> stk;
        getline(cin,s);
        bool flag=true;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                stk.push(s[i]);
            else
            {
                if(stk.empty())
                {
                    flag=false;
                    break;
                }
                else if(s[i]==')'&&stk.top()!='(')
                {
                    flag=false;
                    break;
                }
                else if(s[i]==']'&&stk.top()!='[')
                {
                    flag=false;
                    break;
                }
                else if(s[i]=='}'&&stk.top()!='{')
                {
                    flag=false;
                    break;
                }

                stk.pop();
            }
        }
        if(flag&&stk.empty())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }



    return 0;

}



/*#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

bool is_matching(char opening, char closing)
{
    for(auto p: {"()","[]","{}"})
        {
            if(p[0]==opening&&p[1]==closing)
                return true;
        }
        return false;
}

bool is_balanced(string s)
{
    stack <char> stk;
    for(char c: s)
    {
        if(c=='('||c=='['||c=='{')
            stk.push(c);
        else{
            if(stk.empty())
                return false;
            if(is_matching(stk.top(),c)){
                stk.pop();
            }
            else{
                return false;
            }
        }
    }
    return stk.empty();
}


int main()
{
    fastio;

    ll t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        if(s=="")
        {
            cout<<"Yes"<<endl;
            continue;
        }

        if(is_balanced(s))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }



    return 0;

}
*/
