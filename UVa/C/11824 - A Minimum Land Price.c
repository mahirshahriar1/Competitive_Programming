#include <stdio.h>
#include <math.h>

int main()
{
    int T;

    scanf("%d", &T);
    int arr1[40];
    while(T--)
    {
        int arr[40],i=0;

        for(;;i++)
        {
               scanf("%d", &arr[i]);
               if(arr[i]==0)
                break;
        }
        for(int j=0;j<i-1;j++)
        {
            for(int k=0;k<i-1;k++)
            {
                if(arr[k]>arr[k+1])
                {
                    int temp=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;
                }
            }
        }

        double sum=0;
        for(int j=1,k=i-1;k>=0;j++,k--)
            sum=sum+(2*pow(arr[k],j));

        if(sum>5000000)
            printf("Too expensive\n");
        else
            printf("%.f\n", sum);



    }

}


