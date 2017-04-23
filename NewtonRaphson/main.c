#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void main()
{
     char ch='y';
	 int eq[20],a,b,deg,i,j,der[20],n;
	 float f_a=0,f_b=0,app,app_b,f=0,f_dash=0,l,x_n; //app==approx

	 printf("Enter equation to find roots:\n");
	 printf("Degree: ");
	 scanf("%d",&deg);
	 deg++;
	 for(i=0;i<deg;i++)
	 {
		printf("x^%d: ",i);
		scanf("%d",&eq[i]);
	 }
	 for(i=1;i<deg;i++)
	 {
		der[i-1]=eq[i]*i;
	 }

	 printf("\nEquation: ");
	 for(i=deg-1;i>0;i--)
     {
        if(eq[i]!=0)
            printf("%d[x^%d] + ",eq[i],i);
     }
     printf("%d\n",eq[i]);

     printf("\nDerivative: ");
	 for(i=deg-2;i>0;i--)
     {
        if(der[i]!=0)
            printf("%d[x^%d] + ",der[i],i);
     }
     printf("%d\n",der[i]);
    do
    {


        printf("\nEnter x0 (inital value): ");
        scanf("%f",&l);
        printf("Enter number of Iterations required: ");
        scanf("%d",&n);
        //approx now i is no of iterations
         for(i=0;i<n;i++)
         {
            f=0;
            f_dash=0;
            if(i!=0)
            {
                l=x_n;
            }
            f+=eq[0];
            f_dash+=der[0];
            for(j=1;j<deg;j++)
            {
                  f+=eq[j]*pow(l,j);
                  if(j<deg-1) //derivatives deg is one less
                    f_dash+=der[j]*pow(l,j);
            }

            x_n=l-(f/f_dash);

            printf("%d approx: %f\n",i+1,x_n);

         }

        printf("Do you wish to change x0 and no of iterations (y/n)? : ");
        scanf(" %c",&ch);
    }while(ch=='y');



}
