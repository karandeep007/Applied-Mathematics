/* Divided Difference interpolation */
#include <iostream>
using namespace std;

float divdiff(float x[100],float curr[100],int n,int h,float x0,float first);
int main()
{
    int n,dd_n,h=1;
    float x[100],y[100],x0,ans,first;
    cout<<"----------Newton's Divided Difference Interpolation----------"<<endl<<endl;
    cout<<"Enter number of values available: "; cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter x"<<i<<" : "; cin>>x[i];

    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter y"<<i<<" : "; cin>>y[i];
    }
    first=y[0];
    cout<<endl<<"Enter the [x] at which interpolation is required: "; cin>>x0;;
    ans=divdiff(x,y,n,h,x0,first);

    cout<<"F("<<x0<<") : "<<ans<<endl;
    return 0;
}
float divdiff(float x[100],float curr[100],int n,int h,float x0, float first)
{
    int i;
    float temp=1,nxt[100];

    if(n==1)
    {
      return first;
    }
    else
    {
        for(i=0;i<n-1;i++)
        {
           nxt[i]=(curr[i+1]-curr[i])/(x[i+h]-x[i]);
        }
        for(i=0;i<h;i++)
        {
            temp*=(x0-x[i]);
        }

        return ((temp*nxt[0])+divdiff(x,nxt,n-1,h+1,x0,first) );
    }
}
