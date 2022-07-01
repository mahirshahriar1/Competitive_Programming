//Brute force implementation.. need to do a better algorithm for this one

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    vector <string> s;
    vector <int> arr;
    string input;
    int inp;

    for(int i=0;i<t;i++)
    {
        cin.ignore();
        cin>>input;
        cin>>inp;
        s.push_back(input);
        arr.push_back(inp);
    }
    vector <string> scopy=s;
    sort(scopy.begin(), scopy.end());

    int mini=1000;
    for(int i=0;i<t;i++)
    {
        int xd;
        int ans=0,mini=1000;
        for(int j=0;j<t;j++)
        {
            if(scopy[i]==s[j])
            {
                xd=j;
                for(int k=0;k<t;k++)
                {
                    if(scopy[i]==s[k]&&arr[k]>arr[xd])
                    {
                        xd=k;
                    }

                }
                s[xd].erase();
                arr[xd]=-1;
                cout<<xd+1<<endl;
                break;
            }

        }

    }
    return 0;
}





