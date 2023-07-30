#include <stdio.h>

int main()
{
    int a,b,c,max,x;
    while(1)
    {
        x=0;
        scanf("%d %d %d", &a,&b,&c);
        if(a==0&&b==0&&c==0)
            break;

        if(a>b&&a>c)
        {
            max=a*a;
            x=b*b+c*c;
        }
        else if(b>c&&b>a)
        {
            max=b*b;
            x=a*a+c*c;
        }
        else
        {
            max=c*c;
            x=a*a+b*b;
        }

        if(max==x)
            printf("right\n");
        else
            printf("wrong\n");


    }



    return 0;
}
