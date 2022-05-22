#include<bits/stdc++.h>
using namespace std;
int ar[100];
int n;
double function_(double x)
{
    double res=ar[n];
    for(int i=n-1;i>=0;i--)
    {
        res=res*x+ar[i];
    }
    return res;
}
int main()
{
    double a,b,f0,f1,f2,x1,x2,x0;
    cout<<"Enter the highest degree: ";
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter the upper and lower limit: ";
    cin>>a>>b;
    while(true)
    {
        double dx=0.00001;
        double e=00.000001;
        x1=a;
        x2=x1+dx;
        f1=function_(x1);
        f2=function_(x2);
        if(f1*f2<=0)
        {
            while(true)
            {
                x0=(x1+x2)/2.0;
                f0=function_(x0);
                if(f1*f0<0)
                {
                    x2=x0;
                }
                else{
                    x1=x0;
                }
                double err=fabs((x2-x1)/x2);
                if(err<e)
                {
                    cout<<"between "<<x1<<"and"<<" "<<x2<<"there is a root is: "<<x0<<endl;
                    break;
                }
            }
            if(x2<b)
            {
                a=x2;
            }
            else{
                break;
            }
        }
    }
}
