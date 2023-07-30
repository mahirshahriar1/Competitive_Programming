#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    long t,n;

    scanf("%ld", &t);
    while(t--)
    {
        long long count=0;
        scanf("%d", &n);
        int arr1[n],arr2[n];
        for(int i=0;i<n;i++)
            scanf("%d", &arr1[i]);
        for(int i=0;i<n;i++)
           scanf("%d", &arr2[i]);

        int min1=arr1[0],min2=arr2[0];
        for(int i=0;i<n;i++)
        {
            if(min1>arr1[i])
                min1=arr1[i];

        }
        for(int i=0;i<n;i++)
        {
            if(min2>arr2[i])
                min2=arr2[i];

        }
        for(int i=0;i<n;i++)
        {
            if(arr1[i]>min1||arr2[i]>min2)
            {
                long long max=0;
                if(arr1[i]-min1>arr2[i]-min2)
                    max=arr1[i]-min1;
                else
                    max=arr2[i]-min2;
                count+=max;
            }

        }
        printf("%lld\n", count);


    }



    return 0;
}
