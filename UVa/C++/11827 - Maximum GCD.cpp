#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        ll mx=0;
        string s;
        getline(cin, s);
        stringstream ss(s);

        ll x;
        vector <ll> arr;
        while(ss>>x)
            arr.push_back(x);


        for(int i=0; i<arr.size()-1; i++)
        {
            for(int j=i+1; j<arr.size(); j++)
                mx=max(mx,__gcd(arr[i],arr[j]));
        }
        cout<<mx<<endl;
    }


}


