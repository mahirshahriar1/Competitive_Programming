#include <stdio.h>

int validity(long long x,long long y,long long z)
{
    if((x+y>z)&&(x+z>y)&&(y+z>x))
        return 1;
    else
        return 0;
}

int main()
{
    long long n,a,b,c,count=1;
    scanf("%lld",&n);

    while(n--)
    {
        scanf("%lld %lld %lld", &a,&b,&c);
        if(validity(a,b,c))
        {
              if(a==b&&a==c&&b==c)
                printf("Case %lld: Equilateral\n", count);
               else if(a==b||a==c||b==c)
                printf("Case %lld: Isosceles\n", count);
            else
                printf("Case %lld: Scalene\n", count);
        }
        else
            printf("Case %lld: Invalid\n", count);
        count++;

    }

    return 0;
}
