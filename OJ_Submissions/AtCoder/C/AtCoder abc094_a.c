#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int a,b,x;

    scanf("%d %d %d", &a, &b,&x);

    if(a>x)
        printf("NO\n");
    else if(a==x)
        printf("YES\n");
    else if(a<x)
    {
        if(a+b>=x)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
