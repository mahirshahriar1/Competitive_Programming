#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char arr[]="1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,.";

    char text[99999];
    gets(text);

    int length=strlen(text);

    for(int i=0;i<length;i++)
    {
        if(text[i]==' ')
            printf(" ");
        else
        {
            for(int j=0;j<45;j++)
            {
                if(tolower(text[i])==arr[j])
                    printf("%c", arr[j-2]);
            }
        }

    }

printf("\n");

    return 0;
}
