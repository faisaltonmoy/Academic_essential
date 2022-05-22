#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout <<"Enter hoe many values you want for (x,y)";
    cin>>n;
    double x[n+1],xx[n+1],y[n+1],xy[n+1];
    cout<<"Enter the value of x: ";
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    cout<<endl;
    cout<<"Enter the value of y: ";
    for(int i=0;i<n;i++)
    {
        cin>>y[i];
    }
    for(int i=0;i<n;i++)
    {
        xx[i]=x[i]*x[i];
        xy[i]=x[i]*y[i];
    }
    x[n]=y[n]=xx[n]=xy[n]=0;
    for(int i=0;i<n;i++)
    {
        x[n]+=x[i];
        y[n]+=y[i];
        xx[n]+=xx[i];
        xy[n]+=xy[i];
    }
    double a,b;
    b=((n*xy[n])-(x[n]*y[n]))/((n*xx[n])-x[n]*x[n]);
    a=(y[n]/n)-(b*x[n]/n);

    cout<<"The eqn is : y = "<<a<<" + "<<b<<endl;
    return 0;
}
