#include<stdio.h>

int main()
{
    int n;
    int c=1;
	scanf("%d", &n);
    while(n)
    {
        int sum=0,count=0;
        int bricks[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d", &bricks[i]);
            sum=sum+bricks[i];
        }
        int avg=sum/n;
        for(int i=0;i<n;i++)
        {
            while(bricks[i]>avg)
                {
                    bricks[i]--;
                    count++;
                }

        }
      printf("Set #%d\nThe minimum number of moves is %d.\n\n", c++, count);

	scanf("%d", &n);
    }


	return 0;
}
