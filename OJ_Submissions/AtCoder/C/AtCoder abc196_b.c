#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
     char arr[500];

    scanf("%s", &arr);

    for(int i=0; arr[i]!='.';i++)
    {
        if(i==strlen(arr))
            break;
          printf("%c", arr[i]);
    }

    printf("\n");

    return 0;
}
