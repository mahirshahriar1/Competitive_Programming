#include <stdio.h>

int main()
{
    int n,x;
    scanf("%d", &n);

    int count=1;
    while(n--)
    {
        scanf("%d", &x);
        int arr[x];
        for(int i=0;i<x;i++)
            scanf("%d",&arr[i]);
        if(x==1)
            printf("Case %d: %d\n", count, arr[0]);

        int ind=(x/2);
        printf("Case %d: %d\n", count, arr[ind]);

        count++;

    }


    return 0;
}
