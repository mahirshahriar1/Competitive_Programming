#include <stdio.h>
#include <math.h>

int main()
{
    long a,b;
    while(1)
    {
        int count=0;
     scanf("%ld %ld", &a,&b);
     if(a==0&&b==0)
        break;
      if(a>b)
      {
          int temp=b;
          b=a;
          b=temp;
      }
      for(long i=a;i<=b;i++)
      {
        double x=sqrt(i);
        long y=sqrt(i);
        if(x==y)
           count++;
      }
      printf("%d\n", count);
    }

    return 0;
}
