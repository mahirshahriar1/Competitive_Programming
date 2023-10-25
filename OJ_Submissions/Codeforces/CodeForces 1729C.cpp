#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


string s;
bool edit(int a,int b)
{
    return s[a]<s[b];
}

void solve()
{

    cin>>s;
    vector<int> v;

    string temp=s;
    int n=s.size();
    int cost=abs(s[0]-s[n-1]);

    for(int i=1;i<n-1;i++)
    {
        if(s[i]>=min(s[0],s[n-1])&&s[i]<=max(s[0],s[n-1]))
            v.push_back(i);
    }
    sort(v.begin(),v.end(),edit);


    cout<<cost<<' '<<v.size()+2<<"\n1 ";
    if(s[0]>s[n-1])
    {
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i]+1<<' ';
    }
    else{
        for(int i=0;i<v.size();i++)
            cout<<v[i]+1<<' ';
    }
    cout<<n<<endl;
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
