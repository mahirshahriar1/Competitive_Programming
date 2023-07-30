#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{

    int arr[3],k,sum=0;

    for(int i=0; i<3; i++)
        scanf("%d", &arr[i]);

    int max=arr[0],ind=0;
    for(int i=0; i<3; i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            ind=i;
        }
    }

    scanf("%d", &k);

    while(k--)
        arr[ind]=2*arr[ind];

    for(int i=0; i<3; i++)
        sum+=arr[i];

    printf("%d\n", sum);


    return 0;
}
