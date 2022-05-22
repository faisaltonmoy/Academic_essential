#include<bits/stdc++.h>
using namespace std;
int n;
double ar[100][100];
int main()
{
    cout<<"Enter the number of the eqn: ";
    cin>>n;
    cout<<"Enter the coefficients of eqn: ";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cin >> ar[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        double x=ar[i][i];
        for(int j=0; j<n+1; j++)
        {
            ar[i][j]=ar[i][j]/x;
        }

        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                continue;
            }
            double x=ar[j][i];
            for(int k=0; k<n+1; k++)
            {
                ar[j][k]=ar[j][k]-ar[i][k]*x;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ar[i][n]<<" ";
    }
    cout<<endl;
    return 0;
}
