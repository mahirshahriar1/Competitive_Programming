#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int cas;
    while(n--)
    {
        scanf("%d", &cas);
        int arr[cas];

        for(int i=0;i<cas;i++)
            scanf("%d", &arr[i]);

        int max=arr[0],min=arr[0];
        for(int i=0;i<cas;i++)
           {
               if(arr[i]>max)
                max=arr[i];
           }
        for(int i=0;i<cas;i++)
           {
               if(arr[i]<min)
                min=arr[i];
           }
        printf("%d\n", (max-min)*2);

    }
    return 0;

}
