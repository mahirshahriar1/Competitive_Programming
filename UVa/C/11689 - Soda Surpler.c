#include <stdio.h>

int main()
{
    int n,e,f,c,t;
    scanf("%d", &n);
    while(n--)
    {
        int ans=0;
        scanf("%d %d %d", &e, &f,&c);
        t=e+f;

        while((t/c)!=0)
        {
            ans+=t/c;
            t=t/c+t%c;
        }
        printf("%d\n", ans);
    }

    return 0;
}

