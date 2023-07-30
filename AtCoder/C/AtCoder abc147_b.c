#include <stdio.h>
#include <string.h>

int main(){

    char arr[104];
    fgets(arr, 102,stdin);

    int len=strlen(arr)-1;
    int count=0;

    for(int i=0;i<len/2;i++)
    {
        if(arr[i]!=arr[len-i-1])
            count++;
    }
    printf("%d\n", count);

    return 0;
}
