#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

bool comp(pair<pair<string,int>,int> p1,pair<pair<string,int>,int> p2)
{
    if(p1.first.first==p2.first.first)
        return p1.first.second>p2.first.second;
    else
        return p1.first.first<p2.first.first;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<pair<pair<string,int>,int>> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i].first.first>>v[i].first.second;
        v[i].second=i+1;
    }

    sort(v.begin(), v.end(),comp);

    for(auto x:v)
        cout<<x.second<<endl;

    return 0;

}

/*

#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


struct node
{
    string name;
    int rating,pos;
};

#define Node struct node

bool comp(Node x,Node y)
{
    if(x.name==y.name)
        return x.rating>y.rating;
    else
        return x.name<y.name;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<Node> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i].name>>v[i].rating;
        v[i].pos=i+1;
    }

    sort(v.begin(), v.end(),comp);

    for(auto x:v)
        cout<<x.pos<<endl;

    return 0;

}
*/



