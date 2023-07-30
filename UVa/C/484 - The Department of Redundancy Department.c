#include <stdio.h>

int main()
{
    long n,count=0;
    long arr[99999];

    while(scanf("%ld",&n)!=EOF)
    {
        arr[count]=n;
        count++;
    }

    long freq[99999],c=1,k=0;

    for(int i=0;i<count;i++)
    {
        c=1;
        if(arr[i]==-999999)
            continue;
       for(int j=i+1;j<count;j++)
       {
           if(arr[i]==arr[j])
           {
               arr[j]=-999999;
               c++;
           }
       }

            freq[k]=c;
            k++;


    }
    for(int i=0,j=0;i<count;i++)
    {
        if(arr[i]!=-999999)
        {
             printf("%d %d\n", arr[i], freq[j]);
             j++;
        }

    }




    return 0;
}
