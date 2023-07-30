#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[6][6];

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
            scanf("%d", &arr[i][j]);
    }
    int sum[17]= {0},x=0;

    for(int k=0; k<4; k++)

    {
        for(int j=0; j<4; j++)

        {
            sum[x++]=arr[k][j]+arr[k][j+1]+arr[k][j+2]+
                     arr[k+1][j+1]+arr[k+2][j]+arr[k+2][j+1]+arr[k+2][j+2];
        }

    }

    int max=sum[0],ind=0;
    for(int k=0; k<16; k++)
    {
        if(sum[k]>=max)
        {
            ind=k;
            max=sum[k];
        }
    }
  cout<<max<<endl;
}



