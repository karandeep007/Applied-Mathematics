#include <iostream>
#include <math.h>
using namespace std;

void init(float a[100],int deg);
void display(float a[100], int degx, float b[100], int degb);
float cal(float x,float y,float a[100],float b[100],int degx,int degy);
int main()
{
    float pol_x[100],pol_y[100],h,x0,y0,yn,xn,x,ans;
    int i,degx,degy,n;

    cout<<"------Solution to differential Equation Using Euler Method-----"<<endl;
    cout<<"For F(x,y)"<<endl<<"Enter Deg of X: ";
    cin>>degx;
    cout<<"Enter x's coefficients: "<<endl;
    init(pol_x,degx);
    cout<<"Enter Deg of Y: ";
    cin>>degy;
    cout<<"Enter y's coefficients: "<<endl;
    init(pol_y,degy);

    cout<<endl<<"F(x,y): ";
    display(pol_x,degx,pol_y,degy);

    cout<<"Enter interval length (h): ";
    cin>>h;
    cout<<" Enter x0: ";
    cin>>x0;
    cout<<" Enter y0: ";
    cin>>y0;
    cout<<" Enter X-nth: ";
    cin>>xn;
    n= (int)((xn-x0)/h);
    cout<<" No of Iterations required (n): "<<n<<endl<<endl;

    for(i=0,yn=y0,x=x0;i<n;i++,x+=h)
    {
        if(i!=0)
        {
             yn=ans;
        }
        ans=yn+h*cal(x,yn,pol_x,pol_y,degx,degy);
        cout<<" Itr "<<i<<" :"<<ans<<endl;
    }

}

void init(float a[100], int deg)
{
    int i;

    for(i=0;i<=deg;i++)
    {
        cout<<"Enter "<<i<<" : ";
        cin>>a[i];
    }
}
void display(float a[100], int dega, float b[100], int degb)
{
    int i;
    for(i=dega;i>0;i--)
    {
        if(a[i]!=0)

            cout<<" " <<a[i]<<"[x"<<i<<"] +";

    }
    for(i=degb;i>0;i--)
    {
        if(b[i]!=0)
            cout<<" " <<b[i]<<"[y"<<i<<"] +";
    }
    cout<<" "<<a[0]+b[0]<<endl;
}
float cal(float x, float y,float a[100],float b[200],int degx,int degy)
{
    int i,n;
    float ans=0;

    ans=a[0]+b[0];

    for(i=1;i<=degx;i++)
    {
        ans+=a[i]*pow(x,i);
    }
    for(i=1;i<=degy;i++)
    {
        ans+=b[i]*pow(y,i);
    }

    return ans;

}
