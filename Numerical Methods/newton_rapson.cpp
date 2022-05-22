#include<bits/stdc++.h>
using namespace std;
int ar[100],aprime[100];
int n,nprime;
double function_(double x)
{
    double res=ar[n];
    for(int i=n-1;i>=0;i--)
    {
        res=res*x+ar[i];
    }
    return res;
}
double function_prime(double x)
{
    for(int i=n;i>0;i--)
    {
        aprime[n-1]=ar[i]*i;
    }
    nprime=n-1;
    double res=aprime[nprime];

    for(int i=nprime-1;i>=0;i--)
    {
        res=res*x+aprime[i];
    }
    return res;
}

int main()
{
    double e=0.0001;
    double x0,x1;
    cout<<"Enter the degree of the eqn:";
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter the value of x0:";
    cin>>x0;
    while(true)
    {
        x1=x0-(function_(x0))/function_prime(x0);
        double err=fabs((x1-x0)/x1);
        if(err<=e)
        {
            cout<<"The root is :"<<x1;
            cout<<endl;
            break;
        }
        x1=x0;
    }
    return 0;
}
