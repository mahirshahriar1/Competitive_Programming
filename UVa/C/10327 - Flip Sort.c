#include <stdio.h>

int main()
{
    int x;

    while(scanf("%d", &x)!=EOF)
    {
        int arr[x],count=0;
        for(int i=0; i<x; i++)
            scanf("%d", &arr[i]);

        for (int i=0; i<x-1; i++)
        {
            for (int j=0; j<x-i-1; j++)
                if (arr[j]>arr[j+1])
                {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    count++;
                }
        }

        printf("Minimum exchange operations : %d\n", count);

    }
    return 0;

}
