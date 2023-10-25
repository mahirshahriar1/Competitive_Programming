#include <stdio.h>

int main(){

    long n,k,sum=0;

    scanf("%ld %ld", &n, &k);

    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=k;j++)
        {
            sum+=i*100+j;
        }
    }
    printf("%ld\n", sum);

    return 0;
}
