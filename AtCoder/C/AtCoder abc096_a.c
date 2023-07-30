#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    int a,b,count=0;
    scanf("%d %d", &a, &b);

    if(b<a)
        printf("%d\n", a-1);
    else
        printf("%d\n", a);

    return 0;
}
