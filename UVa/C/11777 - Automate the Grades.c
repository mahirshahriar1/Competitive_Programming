#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    int t1,t2,f,a,c1,c2,c3,total,i=0;

    while(n--)
    {
        i++;
        total=0;
        scanf("%d %d %d %d %d %d %d", &t1,&t2,&f,&a,&c1,&c2,&c3);
        if(c1<=c2&&c1<=c3)
            c1=0;
        else if(c2<=c1&&c2<=c3)
            c2=0;
        else
            c3=0;
        total=t1+t2+f+a+(c1+c2+c3)/2;
        int x=total/10;
        if(x==10)
        {
            printf("Case %d: A\n", i);
            continue;
        }
        if(x<=5)
        {
            printf("Case %d: F\n",i);
            continue;
        }
        switch(x)
        {
            case 9:printf("Case %d: A\n", i); break;
            case 8:printf("Case %d: B\n", i); break;
            case 7:printf("Case %d: C\n", i); break;
            case 6:printf("Case %d: D\n", i); break;
        }

    }


    return 0;
}
