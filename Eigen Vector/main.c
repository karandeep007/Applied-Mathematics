#include <stdlib.h>
#define SIZE 100
void init(float a[SIZE][SIZE],int m,int n);
void disp(float a[SIZE][SIZE],int m,int n);
void multi(float a[SIZE][SIZE], float b[SIZE][SIZE], float x[SIZE][SIZE],int m,int n,int o);
void power(float a[SIZE][SIZE],float eigen_m[SIZE][SIZE],int m,int n);
int main()
{
    float arr[SIZE][SIZE],eig[SIZE][SIZE],e_nxt[SIZE][SIZE];
    int m,n;

    printf("Enter Array\n");
    printf("Rows: ");
    scanf("%d",&m);
    printf("Columns: ");
    scanf("%d",&n);
    init(arr,m,n);

    disp(arr,m,n);

    printf("Initial Eigen Array\n");
    init(eig,n,1);
    disp(eig,n,1);

    multi(arr,eig,e_nxt,m,n,1);
    printf("Ldb0: %f\n",e_nxt[0][0]);
    power(arr,e_nxt,m,n);
}
void init(float a[SIZE][SIZE],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {

        for(j=0;j<n;j++)
        {
            printf("Enter[%d,%d]: ",i,j);
            scanf("%f",&a[i][j]);
        }
    }

}
void disp(float a[SIZE][SIZE],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {

        for(j=0;j<n;j++)
        {
            printf("%.2f ",a[i][j]);
        }
        printf("\n");
    }
}
void multi(float a[SIZE][SIZE], float b[SIZE][SIZE], float x[SIZE][SIZE],int m,int n,int o)
{

    int i,j,k;
    float sum;
    for(i=0;i<m;i++)
    {

        for(j=0;j<o;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
              sum+=a[i][k]*b[k][j];
            }
            x[i][j]=sum;

        }
    }
}
void power(float a[SIZE][SIZE],float eigen_m[SIZE][SIZE],int m,int n)
{
    float e_nxt[SIZE][SIZE],v_nxt,v_cur;
    int i;
    static int it=1;

    v_cur=eigen_m[0][0];
    for(i=0;i<n;i++)
    {
        eigen_m[i][0]/=v_cur;

    }

    multi(a,eigen_m,e_nxt,m,n,1);
    v_nxt=e_nxt[0][0];

    if(fabs(v_cur-v_nxt)<(1e-3))
    {
        printf("\nLdb MAX: %f\n",v_nxt);
        printf("Eigen Matrix: \n");
        disp(eigen_m,3,1);
        return;
    }
    else
    {
        printf("Ldb%d: %f\n",it,v_cur);
        it++;
        power(a,e_nxt,m,n);

    }


}
