#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


int main()
{
    fastio;
    string s;
    cin>>s;
    int n=s.size();
       s+="*";
    int arr[n+10]={0},sum[n+10]={0};

    for(int i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
            arr[i+1]=1;
        else
            arr[i+1]=0;

        sum[i+1]=arr[i+1]+sum[i];
    }
    //for(int i=1;i<=n;i++)cout<<sum[i]<<' ';cout<<endl;

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<sum[b-1]-sum[a-1]<<endl;

    }



    return 0;
}
