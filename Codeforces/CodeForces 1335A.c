#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    long t,x;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &x);
        if(x==1||x==2)
             printf("0\n");

        else if(x%2)
            printf("%d\n", x/2);
        else
            printf("%d\n", (x/2)-1);

    }

    return 0;
}
