#include <stdio.h>

int main()
{
    int n;


    while(scanf("%d", &n)!=EOF)
    {
        int a=n;

        int c=0;
        while(n!=0)
        {
            c+=n/3;
            /*int x=0;
             if((x=n/3)==0)
                 break; */
            n=n/3+n%3;

            if(n==2)
                n++;
            else if(n==1)
                break;
        }


        printf("%d\n", c+a);

    }



    return 0;
}
