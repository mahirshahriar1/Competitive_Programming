#include <stdio.h>
#include <string.h>

int main()
{
    char a[25], b[25], c[25], d[25];
    int m,ca=1,i,j;

    scanf("%d", &m);
    scanf("%*c");
    while(m--)
    {
       gets(a);
       gets(b);

       if(strcmp(a,b)==0)
            printf("Case %d: Yes\n", ca++);

        else
        {
            i=0,j=0;
            while(a[i]!='\0')
            {
                while(a[i]==' ')
                    i++;

                c[j++]=a[i];
                i++;
            }
            c[j]='\0';

            i=0,j=0;
            while(b[i]!='\0')
            {
                while(b[i]==' ')
                    i++;

                d[j++]=b[i];
                i++;
            }
            d[j]='\0';

            if(strcmp(c,d)==0)
                 printf("Case %d: Output Format Error\n", ca++);
            else
                printf("Case %d: Wrong Answer\n", ca++);

        }

    }

    return 0;
}
