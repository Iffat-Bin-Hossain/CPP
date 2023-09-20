#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,h;
    printf("Enter two arms coincide of right angle:");
    scanf("%lf %lf",&a,&b);
    h=sqrt(a*a+b*b);
    printf("hypotenuse :%lf",h);
}
