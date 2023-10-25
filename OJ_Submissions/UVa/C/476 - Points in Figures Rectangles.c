#include <stdio.h>

struct data{
    double x1,y1,x2,y2;
};

int main()
{
    struct data p[10];

    char c;
    int count=0;
    scanf("%c", &c);

    while(1)
    {
        if(c=='*')
            break;

        scanf("%lf%lf%lf%lf", &p[count].x1,&p[count].y1,&p[count].x2,&p[count].y2);
        count++;
        scanf("\n%c", &c);
    }

    double x,y;
    int j=1;
    while(1)
    {
        scanf("%lf %lf", &x, &y);
        if(x==9999.9&&y==9999.9)
            break;
        int flag=1;
        for(int i=0;i<count;i++)
        {
            //printf("%lf %lf\n", x, y);
            if(x>p[i].x1&&y<p[i].y1&&x<p[i].x2&&y>p[i].y2)
            {
                printf("Point %d is contained in figure %d\n", j, i+1);
                flag=0;
            }

        }
        if(flag)
             printf("Point %d is not contained in any figure\n", j);
        j++;
    }

    return 0;
}
