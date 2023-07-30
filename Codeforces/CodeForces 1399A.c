#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    int t,n;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        int arr[n],count=0;
        for(int i=0;i<n;i++)
            scanf("%d", &arr[i]);

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
              if(arr[j]>arr[i])
              {
                  int temp=arr[j];
                  arr[j]=arr[i];
                  arr[i]=temp;
              }
            }
        }

        int flag=1;

            for(int i=0;i<n-1;i++)
            {
                if(abs(arr[i+1]-arr[i])>1)
                {
                    printf("NO\n");
                    flag=0;
                    break;
                }
            }

            if(flag)
                printf("YES\n");

    }

    return 0;
}
