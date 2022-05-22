#include<bits/stdc++.h>
using namespace std;
int ar[100][100];
int n;
double roots[100];
void partialpivoting(int clm)
{
    double mx=ar[clm][clm];
    int mi=clm;
    for(int i=clm;i<n;i++)
    {
        if(fabs(ar[i][clm]>mx))
        {
            mx=fabs(ar[i][clm]);
            mi=i;
        }
    }
    if(mi!=clm)
    {
        for(int i=0;i<n+1;i++)
        {
            swap(ar[clm][i],ar[mi][i]);
        }
    }
}
int main()
{
    cout<<"Enter the number of the eqn: ";
    cin>>n;
    cout<<"Enter the co efficients of the eqn: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin>>ar[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        partialpivoting(i);
        double x=ar[i][i];
        for(int j=0;j<n;j++)
        {
            ar[i][j]=ar[i][j]/x;
        }
        for(int j=i+1;j<n;j++)
        {
            int x=ar[j][i];
            for(int k=0;k<n+1;k++)
            {
                ar[j][k]=ar[j][k]-ar[i][k]*x;
            }
        }
    }
    double root=ar[n-1][n]/ar[n-1][n-1];
    roots[n-1]=root;
    for(int i=n-2;i>=0;i--)
    {
        double sum=0.0;
        for(int j=i+1;j<n;j++)
        {
            sum+=ar[i][j]*roots[j];
        }
        roots[i]=(ar[i][n]-sum)/ar[i][i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<roots[i]<<" ";
    }
    return 0;
}
