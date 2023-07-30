#include<stdio.h>

int main()
{
    long a,b,carry,a1,b1,c,result;

    while(scanf("%ld %ld", &a, &b))
    {
        if(a==0&&b==0)
            break;

        carry=0,c=0;

        while(a||b) 
        {
            a1=a%10;
            a/=10;
            b1=b%10;
            b/=10;

            result=a1+b1+c;

            if(result>9)
            {
                c=1;
                carry++;
            }
            else
                c=0;

        }
        if(carry==0)
            printf("No carry operation.\n");
        else if(carry==1)
            printf("1 carry operation.\n");
        else
            printf("%ld carry operations.\n", carry);

    }



    return 0;
}
