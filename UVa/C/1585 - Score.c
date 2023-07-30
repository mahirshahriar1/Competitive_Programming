#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%*c");
    char str[82];

    while(n--)
    {
        int score=0;
        gets(str);
        int count=1;
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]=='O'||str[i]=='o')
            {
                score=score+count;
                count++;
            }
            else
                count=1;
        }

        printf("%d\n", score);
    }






    return 0;
}
