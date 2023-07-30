#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){

    int h,w;
    scanf("%d %d", &h,&w);

    char arr[h][w];

    for(int i=0;i<h;i++)
    {
        scanf("\n");
         for(int j=0;j<w;j++)
            scanf("%c", &arr[i][j]);
    }

    int flag=0;
      for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
               {
                   if(arr[i][j]=='#')
                   {
                    if(arr[i+1][j]=='#'||arr[i-1][j]=='#' ||arr[i][j+1]=='#' ||arr[i][j-1]=='#')
                        continue;
                    else
                    {
                        flag=1;
                        break;
                    }
                   }
               }
               if(flag)
                break;
        }

        if(flag)
            printf("No\n");
        else
            printf("Yes\n");




    return 0;
}
