#include<stdio.h>

int main()
{
    char ch;
    int count = 0;

    while(scanf("%c",&ch) != EOF)
    {
        if(ch == '"')
        {
            count++;
            if(count%2==1)
                printf("``");
            else
                printf("''");
        }
        else
            printf("%c",ch);
    }

    return 0;
}
