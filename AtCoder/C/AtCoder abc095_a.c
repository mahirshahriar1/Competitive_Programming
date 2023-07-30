#include <stdio.h>
#include <string.h>

int main(){

    char arr[4];

    fgets(arr, 4,stdin);

    int sum=700;

    for(int i=0;i<3;i++)
    {
        if(arr[i]=='o')
            sum=sum+100;
    }
    printf("%d\n", sum);

    return 0;
}
