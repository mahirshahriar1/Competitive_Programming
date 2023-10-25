#include <stdio.h>
#include <math.h>

int main()
{
    int v,t;
    float s;

    while(scanf("%d %d", &v, &t)!=EOF)
    {
        if(t==0)
        {
            printf("0\n");
            continue;
        }

        s=0.5*((float)v/t)*pow((2*t),2);
        printf("%.0f\n", s);
    }


    return 0;
}

/*#include <cstdio>
using namespace std;

int main() {
	// v = u + at
	// d = ut + .5 a t^2

	int v1, t1;
	while(scanf("%d %d", &v1, &t1) != EOF){
		printf("%d\n",2*v1*t1);
	}

	return 0;
}*/
