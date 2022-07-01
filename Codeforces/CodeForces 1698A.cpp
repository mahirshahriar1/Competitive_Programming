#include<bits/stdc++.h>
using namespace std;

int main ()
{
  int t,n,x;
  cin>>t;

  vector <int> arr;
  while(t--)
  {
      cin>>n;
      for(int i=0;i<n;i++)
      {
          cin>>x;
          arr.push_back(x);
      }
      for(int i=0;i<n;i++)
      {
          int ans=arr[i+1],flag=0;
          for(int j=0;j<n;j++)
          {
              if(j==i||j==i+1)
                continue;
              ans=ans^arr[j];
          }
        if(ans==arr[i])
        {
              cout<<ans<<endl;
            break;
        }


      }

      arr.clear();
  }

    return 0;
}





