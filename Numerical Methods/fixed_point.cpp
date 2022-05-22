#include<bits/stdc++.h>
using namespace std;
float function_(float x)
{
    float y;
    y=(cos(x)+1)/3;
    return y;
}
int main()
{
    double ar[100],c=100.0;
    int j=0;
    cout<<"Enter the initial guess:";
    cin>>ar[0];
    while(c>0.001)
    {
        ar[j+1]=function_(ar[j]);
        c=(ar[j+1]-ar[j])/ar[j+1];
        c=fabs(c);
        j++;
        cout<<"iteration: "<<j;
        cout<<endl;
    }
    cout<<"The root is: "<<ar[j];
}
