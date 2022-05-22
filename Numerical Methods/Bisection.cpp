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
    cout<<"Enter the highest degree: ";
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>ar[i];
    }
    double x1,x2,x0,f1,f2,f0;
    do{

        cin>>x1>>x2;
        f1=function_(x1);
        f2=function_(x2);
    }while(f1*f2>0);

    do
    {
        x0=(x1+x2)/2;
        f0=function_(x0);
        if(f1*f0<0)
        {
            x2=x0;
        }
        else{
            x1=x0;
        }

    cout<<"The root is: "<<x0<<endl;


    }while(fabs((x2-x1)/x2)>e);

}
