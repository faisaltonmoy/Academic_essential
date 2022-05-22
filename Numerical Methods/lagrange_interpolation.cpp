#include<bits/stdc++.h>
using namespace std;
#define Max 100
int main()
{
    double x[Max],fx[Max],sum=0.0,xp,lf;
    int n;
    cout<<"Enter the number of set: ";
    cin>>n;
    cout<<"Enter data point and the fuction value of that point: ";
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        cin>>fx[i];
    }
    cout<<"Enter the value at which interpolation is required: ";
    cin>>xp;

    for(int i=0;i<n;i++)
    {
        lf=1.0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                lf*=(xp-x[j])/(x[i]-x[j]);
            }
        }
        sum+=lf*fx[i];
    }
    cout<<"Interpolated function value: at x "<<xp<<" is "<<sum<<endl;

}
