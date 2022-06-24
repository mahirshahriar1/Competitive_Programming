#include <stdio.h>

int main()
{
    int n,k;

    while(scanf("%d %d", &n, &k)!=EOF)
    {
        int sum=n;
        while(n/k!=0)
        {
            sum=sum+n/k;
            n=n/k+n%k;
        }
        printf("%d\n", sum);
    }

    return 0;
}

/*

while(scanf("%d%d",&n&k)==2)
{
    int total=n;
    while(n>=k){
        int renew=n/k;
        total=total+renew;

        n=renew+(n%k);
    }
    printf("%d\n", total);
}*/
