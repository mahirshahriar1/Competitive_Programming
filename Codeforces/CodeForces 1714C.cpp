#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


void solve(){
    int n;
    cin>>n;
    int res=INT_MAX;
    for(int i=0;i<(1<<9);i++){
        int sum=0;
        int curr=0;
        for(int j=0;j<9;j++){
            if(i&(1<<j)){
                curr*=10;
                curr+=j+1;
                sum+=j+1;
            }
        }  
        if(sum==n){
            res=min(res,curr);
        }
    }
    cout<<res<<endl;
   
}



int main()
{
    fastio;

    int t;
    cin>>t;
    int arr[]={0,1,2,3,4,5,6,7,8,9,19,29,39,49,59,69,79,89,189,
            289,389,489,589,689,789,1789,2789,3789,4789,5789,6789,
            16789,26789,36789,46789,56789,156789,256789,356789,456789,
            1456789,2456789,3456789,13456789,23456789,123456789};

    while(t--)
    {
        ll x;
        cin>>x;
        cout<<arr[x]<<endl;

    }

}
