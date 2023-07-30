#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(){

    long n;

    scanf("%ld", &n);

    long long int T, t[n],sum=0;

    scanf("%lld", &T);
    for(int i=0;i<n;i++)
        scanf("%lld", &t[i]);

    for(int i=0;i<n;i++)
    {
        long long int xyz=t[i+1]-t[i];
        if(xyz>=T)
            sum+=T;
        else
            sum+=xyz;
    }
    printf("%lld\n", sum);


    return 0;
}
