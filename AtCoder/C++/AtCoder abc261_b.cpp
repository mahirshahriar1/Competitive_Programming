#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    char arr[n][n];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((arr[i][j]=='-'&&arr[j][i]!='-')
               ||(arr[i][j]=='W'&&arr[j][i]!='L')||
               (arr[i][j]=='D'&&arr[j][i]!='D')||
               (arr[i][j]=='L'&&arr[j][i]!='W'))
            {
                cout<<"incorrect"<<endl;
                return 0;
            }
        }

    }

    cout<<"correct"<<endl;



    return 0;
}


