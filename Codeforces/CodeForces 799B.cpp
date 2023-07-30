#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

bool comp(pair<ll,pair<int, int>> a,pair<ll,pair<int, int>>b)
{
    return a.first<b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n1,n2,x;

    cin>>n1;

    vector <pair<ll,pair<int, int>>> v(n1);

    for(int i=0;i<n1;i++)
        cin>>v[i].first;
    for(int i=0;i<n1;i++)
        cin>>v[i].second.first;
    for(int i=0;i<n1;i++)
        cin>>v[i].second.second;

    sort(v.begin(), v.end(),comp);


    vector<bool> v2(n1,false);
    vector<int> arr(5,0);

    cin>>n2;

    for(int i=0;i<n2;i++)
    {
        bool print=true;
        cin>>x;

        for(int i=arr[x];i<n1;i++)
        {
            if(v2[i]==false&&(x==v[i].second.first||x==v[i].second.second))
            {
                cout<<v[i].first<<" ";
                v2[i]=true;;
                arr[x]=i+1;
                print=false;
                break;
            }

        }
        if(print)
        {
            arr[x]=n1;
            cout<<"-1 ";
        }

    }


    return 0;
}

// using Set below
/*#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
 {
     set<int> col[4];

     int a,b,n,m,i,c;
     int price[200010];

     cin>>n;
     for(i=0;i<n;i++)
       cin>>price[i];  //prices input
     for(i=0;i<n;i++)
     {
         cin>>a;
         col[a].insert(price[i]);
     }
     for(i=0;i<n;i++)
     {
         cin>>b;
         col[b].insert(price[i]);
     }
     cin>>m;
     for(i=0;i<m;i++)
     {
         cin>>c;
         if(col[c].size()==0)
         {
             cout<<"-1 ";
         }
         else
         {
             auto itr=col[c].begin();
             int k=*itr;
             cout<<k<<" ";

             itr=col[1].find(k);
             if(itr!=col[1].end())
                col[1].erase(itr);
             itr=col[2].find(k);
             if(itr!=col[2].end())
                col[2].erase(itr);
             itr=col[3].find(k);
             if(itr!=col[3].end())
                col[3].erase(itr);
         }

    }
     return 0;
 }



*/
