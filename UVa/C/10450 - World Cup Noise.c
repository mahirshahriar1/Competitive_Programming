#include<stdio.h>

int main()
{
    long long n, count=1;
    scanf("%lld", &n);

    while(n--)
    {
        long long x;
        scanf("%lld", &x);

        long long t1,t2, fib=0, term,i;

        t1=2;
        t2=3;
        if(x==1)
            printf("Scenario #%lld:\n2\n\n", count);
        else if(x==2)
            printf("Scenario #%lld:\n3\n\n", count);
        else
        {
            for(i=3; i<=x; i++)
            {
                fib=t1+t2;
                    t1=t2;
                    t2=fib;
            }
            printf("Scenario #%lld:\n%lld\n\n", count, fib);
        }

        count++;

    }

    return 0;
}
