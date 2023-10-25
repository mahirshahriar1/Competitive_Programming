#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


bool check(const vector<int>& v, int num, int val)
{
    int container=1;
    int capacity=val;

    for(int i=0;i<v.size();i++)
    {
        if(v[i]>val)
            return false;
        if(v[i]>capacity)
        {
            if(container==num)
                return false;

            container++;
            capacity=val;
        }
        capacity-=v[i];
    }
    return true;
}



int solve(int a,int num)
{
    vector<int> v(a);
    for(int i=0;i<a;i++)
        cin>>v[i];
    int l=0, r=1000000000; //1000*1000000

    int res=0;
    while(l<=r){
        int mid = (l + r) / 2;
        if (check(v,num,mid)){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return res;
}


int main()
{
    fastio;

    int a,b,t,kas=0;

    cin>>t;

    while(t--)
    {
        cin>>a>>b;
        cout<<"Case "<<++kas<<": "<<solve(a,b)<<endl;
    }

    return 0;
}

