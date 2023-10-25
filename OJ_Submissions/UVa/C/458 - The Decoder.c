#include<stdio.h>
int main()
{
 char ch;

 while(scanf("%c", &ch)!=EOF)
 {
     if(ch=='\n')
         printf("%c", ch);
     else
        printf("%c", ch-7);

 }

    return 0;
}
