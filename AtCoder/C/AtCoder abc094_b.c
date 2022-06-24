#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    int n,m,x,c1=0,c2=0;
    scanf("%d %d %d", &n, &m,&x);

    int arr[m];

    for(int i=0;i<m;i++)
        scanf("%d", &arr[i]);

    for(int i=0;arr[i]<x;i++)
        c1++;

     for(int i=m-1;arr[i]>x;i--)
        c2++;

    int result=(c1<c2)?c1:c2;

    printf("%d\n", result);


    return 0;
}
