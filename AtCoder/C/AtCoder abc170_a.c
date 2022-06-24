#include <stdio.h>

int main(){

    int arr[5];

    for(int i=0;i<5;i++)
        scanf("%d", &arr[i]);

    for(int i=0;i<5;i++)
    {
        if(arr[i]==0)
        {
            printf("%d\n", i+1);
            break;
        }
    }


    return 0;
}
