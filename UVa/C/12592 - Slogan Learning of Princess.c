#include <stdio.h>
#include <string.h>

struct array{
    char line1[105];
    char line2[105];
};

int main()
{
    int n;
    scanf("%d", &n);

    struct array arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("\n");
        fgets(arr[i].line1, 100, stdin);
        scanf("\n");
        fgets(arr[i].line2, 100, stdin);
    }

    int x;
    scanf("%d", &x);

     char input[105];

     for(int i=0;i<x;i++)
    {
        scanf("\n");
        fgets(input, 100, stdin);
         for(int i=0;i<n;i++)
         {
             if(strcmp(arr[i].line1,input)==0)
                printf("%s", arr[i].line2);
         }

    }

    return 0;
}
