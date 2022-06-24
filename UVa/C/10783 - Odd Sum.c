#include <stdio.h>
int main()
{
  int n,a,b;
  scanf("%d", &n);
    int cas=1;
  while(n--)
  {
      int sum=0;
      scanf("%d %d", &a, &b);
      for(int i=a;i<=b;i++)
      {
          if(i%2)
            sum+=i;
      }
      printf("Case %d: %d\n", cas, sum);
      cas++;
  }


    return 0;
}
