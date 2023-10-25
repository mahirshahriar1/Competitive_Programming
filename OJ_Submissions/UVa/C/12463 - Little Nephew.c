#include <stdio.h>
int main()
{
    int a,b,c,d,e;

    while(scanf("%d %d %d %d %d", &a, &b,&c,&d,&e))
    {
        if(!a&&!b&&!c&&!d&&!e)
            break;
        printf("%d\n", a*b*c*d*d*e*e);
    }

    return 0;
}
