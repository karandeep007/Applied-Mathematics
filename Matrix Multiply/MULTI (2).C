#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
void multi(int a[100][100],int b[100][100],int x[100][100],int m,int n,int o);
int main()
{
	int p[100][100],q[100][100],f[100][100],m,n,o,l,i,j;

    printf("MATRIX MULTIPLICATION\n\n");
	printf("Enter size of Matrix A (mxn): \nm = ");
	scanf("%d",&m);
	printf("n = ");
	scanf("%d",&n);
	printf("Enter size of Matrix B (oxl): \no = ");
	scanf("%d",&o);
	printf("l = ");
	scanf("%d",&l);
	if(n!=o)
	{
		printf("Cannot multiply! (n!=o)\n");
		return 1;
	}

	printf("Enter A\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("[%d.%d]: ",i,j);
			scanf("%d",&p[i][j]);
		}
	}
	printf("\nEnter B\n"); //o==n
	for(i=0;i<n;i++)
	{
		for(j=0;j<l;j++)
		{
			printf("[%d.%d]: ",i,j);
			scanf("%d",&q[i][j]);
		}
	}
	multi(p,q,f,m,n,l);
	printf("\nA X B :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<l;j++)
		{
			printf("%4d ",f[i][j]);
		}
		printf("\n");
	}

}
void multi(int a[100][100],int b[100][100],int x[100][100],int m,int n,int o)
{
	int i,j,k,sum_r;

	for(i=0;i<m;i++)
	{
		for(j=0;j<o;j++)
		{
			sum_r=0;
			for(k=0;k<n;k++)
			{
				sum_r+=a[i][k]*b[k][j];
			}
			//printf("%d",sum_r);
			x[i][j]=sum_r;
		}
	}

}



