#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    long long int a,b,c;
    scanf("%lld %lld %lld", &a,&b,&c);

    if(c%2==0)
    {
        if(abs(a)>abs(b))
            printf(">\n");
        else if(abs(a)<abs(b))
            printf("<\n");
        else
            printf("=\n");
    }
    else
    {
        if(a>b)
            printf(">\n");
        else if(a<b)
            printf("<\n");
        else
            printf("=\n");
    }
    return 0;
}
