#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ar[20][20],x[20],e,big,temp,relerror,sum;
    int n,maxit;
    char ch;
    cout<<"Enter the size of the eqn: ";
    cin>>n;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin>>ar[i][j];
        }
    }
    cout<<"Enter the relative error & number of iterations: ";
    cin>>e>>maxit;
    for(int i=1;i<=n;i++)
    {
        x[i]=0;
        for(int k=1;k<=maxit;k++)
        {
            big=0;
            for(int i=1;i<=n;i++)
            {
                sum=0;
                for(int j=1;j<=n;j++)
                {
                    if(i!=j)
                    {
                        sum=sum+ar[i][j]*x[j];
                    }
                }
                temp=(ar[i][n+1]-sum)/ar[i][i];
                relerror=fabs((x[i]-temp)/temp);
                if(relerror>big)
                {
                    big=relerror;
                }
                x[i]=temp;
            }
            if(big<=e)
            {
                for(int i=1;i<<=n;i++)
                {
                    cout<<"  "<<x[i];
                }
            }
        }
    }
    return 0;
}
