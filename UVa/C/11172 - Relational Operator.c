#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    long a,b;
    scanf("%d", &t);
    if(t>=15)
        exit(1);
    for(int i=0;i<t;i++)
    {
        scanf("%ld %ld", &a, &b);
        if(a>b)
            printf(">");
        else if(a<b)
            printf("<");
        else
            printf("=");
        printf("\n");
    }

    return 0;
}
