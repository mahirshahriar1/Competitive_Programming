#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

const int N=1e7+1;
int SOD[N], ANS[N];

void sieve_SOD(int n){

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
            SOD[j]+=i;
    }

    memset(ANS,-1,sizeof(ANS));

    for(int i=1;i<=n;i++)
    {
        if(SOD[i]>1e7)
            continue;
        else if(ANS[SOD[i]]==-1)
            ANS[SOD[i]]=i;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve_SOD(1e7);

    int t;cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<ANS[x]<<endl;
    }


    return 0;
}



