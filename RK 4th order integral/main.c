#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float cal_f(float m,float n,float dx[20],float dy[20],int deg2,int deg1);
void showeq(float dy[20],float dx[20],int deg1,int deg2);
int main()
{
    float x0,y0,m,n,dy[20],dx[20],h,k1,k2,k3,k4,keq,y,temp;
    int deg1,deg2,i;

    printf("Solving Higher order Derivatives using RK Method, 4th order\n Polynomials only\n\n");
    printf("Enter dy/dx=f(x,y)\n");
    printf("Degree of y in f(x,y): ");
    scanf("%d",&deg1);
    for(i=0;i<=deg1;i++)
    {
        printf("Enter y^%d coeff.: ",i);
        scanf("%f",&dy[i]);
    }
    printf("Degree of x in f(x,y): ");
    scanf("%d",&deg2);
    for(i=0;i<=deg2;i++)
    {
        printf("Enter x^%d coeff.: ",i);
        scanf("%f",&dx[i]);
    }

    showeq(dy,dx,deg1,deg2);

    printf("Enter width of interval,h: ");
    scanf("%f",&h);
    printf("Enter x0: ");
    scanf("%f",&x0);
    printf("Enter y0: ");
    scanf("%f",&y0);
    printf("\n");
    //k1 ->f(x,y)
    temp=cal_f(x0,y0,dx,dy,deg2,deg1);

    k1=temp*h;
    //k2 -> f(m,n)
    m=x0+h/2,n=y0+k1/2;
    temp=cal_f(m,n,dx,dy,deg2,deg1);

    k2=h*temp;
    //k3 -> f(m,n)
    m=x0+h/2,n=y0+k2/2;
    temp=cal_f(m,n,dx,dy,deg2,deg1);

    k3=h*temp;
    //k4 -> f(m,n)
    m=x0+h,n=y0+k3;
    temp=cal_f(m,n,dx,dy,deg2,deg1);

    k4=h*temp;

    keq=((float)1/6)*(k1+2*k2+2*k3+k4);
    //y(h)
    y=keq+y0;
    printf("K1: %f\nK2: %f\nK3: %f\nK4: %f\nKeq: %f\ny(%2.1f)=%f",k1,k2,k3,k4,keq,h,y);


    return 0;
}
float cal_f(float m,float n,float dx[20],float dy[20],int deg2,int deg1)
{
    float temp=0;
    int i;

    temp=dy[0]+dx[0];
    for(i=1;i<=deg1;i++)
    {
        if(n!=0)
            temp+=(dy[i]*pow(n,i)) ;
        ;
    }
    for(i=1;i<=deg2;i++)
    {
        if(m!=0)
            temp+=(dx[i]*pow(m,i)) ;
    }

    return temp;
}
void showeq(float dy[20],float dx[20],int deg1,int deg2)
{
    int i;
    printf("\n");
    for(i=deg1;i>=0;i--)
    {
        if(dy[i]>0)
            printf("+");
        if(dy[i]!=0)
            printf("%2.1f[y%d] ",dy[i],i);
    }
    for(i=deg2;i>=0;i--)
    {
        if(dx[i]>0)
            printf("+");
        if(dx[i]!=0)
            printf("%2.1f[x%d] ",dx[i],i);
    }
    printf("\n\n");
}
