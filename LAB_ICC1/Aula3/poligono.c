#include <stdio.h>
#include <math.h>

int main(void){

    double n, l, area, ang_int, tang;
    double pi=3.14159265358979323846;

    scanf("%lf %lf", &n, &l);

    ang_int = ((((n-2)*180)/n)*pi)/360;

    printf("%lf\n", ang_int);

    tang = tan(ang_int);

    printf("%lf\n", tang);

    area = ((n*l)/2)*(tang*(l/2));

    //area = ((n*l)/2)*(l/(2*tan(pi/n)));

    printf("%.6lf\n", area);

    return 0;
}