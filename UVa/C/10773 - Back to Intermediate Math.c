#include <stdio.h>
#include <math.h>


int main()
{
    int n,i=0;
    float d,v,u,x;
    scanf("%d", &n);

    while(n--)
    {
        i++;
        scanf("%f %f %f", &d, &v, &u);
        if(u<=v||!u||!v)
            printf("Case %d: can't determine\n", i);
        else
        {
            x=(d/u)-(d/sqrt(u*u-v*v));
            if(x<0)
                printf("Case %d: %.3f\n",i, -x);
            else
                printf("Case %d: %.3f\n", i,x);

        }

    }

    return 0;
}
