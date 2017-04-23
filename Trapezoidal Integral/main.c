#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,d,fx[20],j,n;
    float h,left=0,right=0,i,y,integral;

    printf("Integral Evaluation using Trapezoidal Rule\n\n");
    printf("Integral from a->b for f(x)dx\n");
    printf("Enter Lower limit,a: ");
    scanf("%d",&a);
    printf("Enter Upper limit,b: ");
    scanf("%d",&b);
    printf("Enter width of interval,h: ");
    scanf("%f",&h);
    n=(b-a)/h+1;
    printf("n: %d\n",n);
    printf("Enter f(x) , polynomials only \n");
    printf("Degree of f(x): ");
    scanf("%d",&d);

    for(j=0;j<=d;j++)
    {
        printf("Enter x^%d: ",j);
        scanf("%d",&fx[j]);
    }

    //trapezoidal rule
    for(i=0;i<=b;i+=h)
    {

        y=0;
        for(j=0;j<=d;j++)
        {
            y+=(fx[j]*pow(i,j));
        }
        //reciprocal
        y=1/y;
        if(i==0||i==b)
        {
            left+=y;
        }
        else
            right+=y;

    }
    integral=(h/2)*(left+ 2*right);
    printf("Integral from a to b= %f\n",integral);


}
