#include <stdio.h>

int main()
{
    long i,j;
    while(scanf("%ld %ld", &i, &j) == 2)
    {
        if(i>0 && i<1000000 && j>0 && j< 1000000)
        {
            long a=i;
            long b=j;
            if(i>j)
            {
                a=j;
                b=i;
            }
            long max=0,count;

            for(long x=a; x<=b; x++)
            {
                long n=x;
                count=1;
                while(n!=1)
                {
                    if(n%2)
                    {
                        n=3*n+1;
                        count++;
                    }

                    else
                    {
                        n=n/2;
                        count++;
                    }

                }
                if(count>max)
                    max=count;
            }
            printf("%ld %ld %ld\n", i,j, max);

        }

    }


    return 0;
}
