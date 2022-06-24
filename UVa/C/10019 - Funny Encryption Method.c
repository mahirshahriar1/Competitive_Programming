#include <stdio.h>
#include <math.h>


int main()
{
    int x;
    scanf("%d", &x);

    while(x--)
    {
        long n,b1=0,b2=0;
        scanf("%ld", &n);

        long bin=n;

        while(bin)
        {
            b1=b1+(bin%2);
            bin/=2;
        }

        long q;

        while(n)
        {
            q=n%10;
            if(q==1||q==2||q==4||q==8)
                b2++;
            else if(q==3||q==5||q==6||q==9)
                b2+=2;
            else if(q==7)
                b2+=3;
            n/=10;
        }
         printf("%ld %ld\n",b1,b2);

    }



    return 0;
}
