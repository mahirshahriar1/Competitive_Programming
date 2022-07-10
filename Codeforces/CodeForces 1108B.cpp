#include<bits/stdc++.h>
using namespace std;
#define long long int ll;


int main(){
    int n;
    cin>>n;
    int temp;
    vector<ll> v;
    
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    ll x,y;
    x=v[v.size()-1];
    
    y=-1;
    
    for(int i=0;i<v.size();i++)_
    {
        if(x%v[i]==0){
            if(v[i]==v[i+1])
                i++;
        }
        v[i]=-1;
    }
    sort(v.begin(), v.end());
    
    y=v[v.size()-1];
    
    cout<<x<<" "<<y<<endl;

    return 0;
}

/*vector<long > divisors(long  n)
{
    vector<long > div;
    for (long  i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            if (n / i != i)
            {
                div.push_back(n / i);
            }
        }
    }

    sort(div.begin(), div.end());
    return div;
}



int main ()
{

    long t,x;

    cin>>t;

    vector <long> arr;
    for(int i=0; i<t; i++)
    {
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());

    long ans1=arr[t-1];
    vector <long> arr2 =divisors(arr[t-1]);

    for(int i=0; i<arr2.size(); i++)
    {
        for(int j=0; j<t; j++)
        {
            if(arr2[i]==arr[j])
            {
                arr2[i]=-1;
                arr[j]=-1;
                break;
            }
        }

    }

    vector <long> ans;

    for(int i=0;i<t;i++)
    {
        if(arr[i]!=-1)
            ans.push_back(arr[i]);
    }
    cout<<ans1<<" "<<ans[ans.size()-1]<<endl;

    return 0;

}*/










