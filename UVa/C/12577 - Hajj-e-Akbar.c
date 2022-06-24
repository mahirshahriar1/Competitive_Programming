#include<stdio.h>
#include<string.h>

int main()
{
    char word[10];
    scanf("%s", word);
    int c=1;

    while(1)
    {
        if(word[0]=='*')
            break;
        if(strcmp(word,"Hajj")==0)
            printf("Case %d: Hajj-e-Akbar\n", c);
        else
            printf("Case %d: Hajj-e-Asghar\n", c);
        scanf("%s", word);
        c++;
    }

    return 0;
}
