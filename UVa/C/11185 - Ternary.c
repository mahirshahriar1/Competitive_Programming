#include <stdio.h>
int main()
{
    long long i,n,j,a[10000];
    while(scanf("%lld",&n))
    {
        if(n<0)
            break;
        else if(n==0)
        {
            printf("0\n");
        }
        else
        {
            i=0;
            for(i=0; n>0; i++)
            {
                a[i]=n%3;
                n=n/3;
            }

            i=i-1;
            for(j=i;j>=0;j--)
                printf("%lld",a[j]);

            printf("\n");
        }
    }
    return 0;
}
