#include <iostream>
#include <math.h>

using namespace std;

class eq
{
    float fx[100],gx[100],sinx[100],cosx[100];
    int degf, degg,degsin,degcos;
    /* f[x] polynomial in numerator
     * g[x] polynomial in denominator
     * sinx sin's in numerator
     * cosx cos's in denominator
    */
public:
    eq():degf(-1),degg(-1),degsin(-1),degcos(-1)
    {
        fx[0]=0;
        gx[0]=1;
        cosx[0]=0;
        sinx[0]=0;

    }
    void geteq();
    void showeq();
    float sol(float x);

};
void eq::geteq()
{

    int i;
    char ch;
    cout<<"Poly in Numerator (y/n)?: ";
    cin>>ch;
    if(ch=='y')
    {
        cout<<"Enter deg of F[x]: ";
        cin>>degf;
        for(i=0;i<=degf;i++)
        {
            cout<<"Enter "<<i<<" coeff. :";
            cin>>fx[i];
        }
    }
    cout<<"Poly in Denominator (y/n)?: ";
    cin>>ch;
    if(ch=='y')
    {
        cout<<"Enter deg of G[x]: ";
        cin>>degg;
        for(i=0;i<=degg;i++)
        {
            cout<<"Enter "<<i<<" coeff. :";
            cin>>gx[i];
        }
    }
    cout<<"Do you want Sine terms in numerator? (y/n) :";
    cin>>ch;
    if(ch=='y')
    {
        cout<<"How many terms? :";
        cin>>degsin;
        cout<<"Enter nth coeff. ( for sin(ax) where a is +ve coeff.) in radians"<<endl;
        for(i=0;i<degsin;i++)
        {
            cout<<"Enter "<<i+1<<" coeff.: ";
            cin>>sinx[i];
        }

    }
    cout<<"Do you want Cosine terms in numerator? (y/n) :";
    cin>>ch;
    if(ch=='y')
    {
        cout<<"How many terms? :";
        cin>>degcos;
        cout<<"Enter nth coeff. ( for sin(ax) where a is coeff.)"<<endl;
        for(i=0;i<degcos;i++)
        {
            cout<<"Enter "<<i<<" coeff.: ";
            cin>>cosx[i];
        }

    }
}
void eq::showeq()
{
    int i,x;
    cout<<"Of the form F[x]/G[x]"<<endl;
    cout<<"F[x]:";
    cout<<"  ";
    if(degsin>0)
    {
        for(i=0;i<degsin;i++)
        {
            cout<<"sin("<<sinx[i]<<"x) + ";
        }
    }
    if(degcos>0)
    {
        for(i=0;i<degcos;i++)
        {
            cout<<"cos("<<cosx[i]<<"x) + ";
        }
    }
    if(degf>=0)
    {

        for(i=degf;i>=0;i--)
        {
            if(fx[i]!=0)
            {
                cout<<fx[i]<<"[x^"<<i<<"] + ";

            }
            if(i==0)
                cout<<fx[i];
        }
    }
    else
    {
        cout<<"0";
    }
    cout<<endl;
    cout<<"G[x]:";
    cout<<"  ";
    if(degg>=0)
    {

        for(i=degg;i>=0;i--)
        {
            if(gx[i]!=0)
            {
                cout<<gx[i]<<"[x^"<<i<<"] + ";

            }
            if(i==0)
                cout<<gx[i]<<endl;
        }

    }
    else
    {
        cout<<"1"<<endl;
    }


}
float eq::sol(float x)
{
    float y=0,temp;
    int i;

    if(degf>=0)
    {
        y+=fx[0];
        for(i=1;i<=degf;i++)
        {
            y+=fx[i]*pow(x,i);
        }
    }
    if(degcos>=0)
    {
        for(i=0;i<degcos;i++)
        {
            temp=cosx[i]*x;
            y+=cos(temp);
        }
    }
    if(degsin>=0)
    {
        for(i=0;i<degsin;i++)
        {
            temp=sinx[i]*x;
            y+=sin(temp);
        }
    }
    if(degf>=0)
    {
        temp=gx[0];
        for(i=1;i<=degg;i++)
        {
            temp+=gx[i]*pow(x,i);
        }
        y/=temp; //of the form F[x]/G[x]
    }

    return y;

}
int main()
{
    eq eq1;
    float a,b,h,x0,ans,temp;
    int n,i;

    ans=0;
    eq1.geteq();
    eq1.showeq();

    cout<<"Enter Lower Limit : ";
    cin>>a;
    cout<<"Enter Upper Limit: ";
    cin>>b;
    cout<<"Enter width of interval (h): ";
    cin>>h;
    n=(b-a)/h;
    cout<<"Number of iterations required: "<<n<<endl;

    for(x0=a,i=0; x0<=b; x0+=h,i++)
    {
        temp=eq1.sol(x0);
        cout<<"Y"<<i<<" : "<<temp<<endl;
        if(i==0||i==n)
        {
            ans+=temp;
        }
        else if(i%2==0)
        {
            ans+=2*temp;
        }
        else if(i%2!=0)
        {
            ans+=4*temp;
        }

    }

    ans*=(h/3);

    cout<<"Integral for F[x]/G[x] over "<<a<<" to "<<b<<" w.r.t x = "<<ans<<endl;

}
