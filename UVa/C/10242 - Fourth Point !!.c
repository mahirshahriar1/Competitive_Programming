#include <stdio.h>

int main()
{
    double ax,ay, bx,by,cx,cy,dx,dy;

    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &ax,&ay, &bx,&by,&cx,&cy,&dx,&dy)!=EOF)
    {
        float x,y;
        if(ax==cx&&ay==cy)
        {
            x=dx-ax;
            y=dy-ay;
            printf("%.3lf %.3lf..\n", bx+x, by+y);
        }
        else if(bx==cx&&by==cy){
             x=bx-ax;
             y=by-ay;

        printf("%.3lf %.3lf\n", dx-x, dy-y);
        }
        else if(ax==dx&&ay==dy)
        {
            x=cx-ax;
            y=cy-ay;
            printf("%.3lf %.3lf\n", bx+x, by+y);
        }
        else if(bx==dx&&by==dy)
        {
            x=cx-bx;
            y=cy-by;
            printf("%.3lf %.3lf\n", ax+x, ay+y);
        }


    }


    return 0;
}
