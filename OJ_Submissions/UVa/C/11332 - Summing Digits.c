#include <stdio.h>

int main()
{

    long long n,sum;

    while(1)
    {
        scanf("%lld",&n);
            if(n==0)
                break;

        label:
        sum=0;
        while(n!=0)
        {
            sum=sum+n%10;
            n/=10;
        }
        if(sum>9)
        {
            n=sum;
            goto label;
        }


        printf("%lld\n", sum);


    }

    return 0;
}

/* while(scanf("%lld", &x))
    {
        if (x == 0)
            break;

        while (x/10!=0)
        {
            sum = 0;
            while (x != 0)
            {
                sum = sum + x%10;
                x /= 10;
            }
            x = sum;
        }
    printf("%lld\n", x);
    }*/

