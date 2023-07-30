#include<bits/stdc++.h>
using namespace std;
 
int kas=0;

void solve()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int n;
    cin>>n;
    cout<<"Case "<<++kas<<":"<<endl;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        cout<<((a>x1&&a<x2&&b>y1&&b<y2)?"Yes":"No")<<endl;        
    }    
  
}

int main()
{
    int t,x,d;
     #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif
    cin>>t;
    while(t--)
    {
       solve();
    }
 
    return 0;
}
 
