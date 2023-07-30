#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,d;
    cin>>a>>b>>d;

    double in_degree=atan2(b,a);

    double final_degree= (acos(-1)*d/180)+in_degree;

    double hyp=sqrt(a*a+b*b);
    double a1=hyp*cos(final_degree);
    double a2=hyp*sin(final_degree);

    printf("%.10f %.10f\n", a1,a2);


    return 0;

}
