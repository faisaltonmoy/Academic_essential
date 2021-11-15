#include<bits/stdc++.h>
using namespace std ;

void Find(int dp[100][100], int w[], int n,int cap)
{
    int i=n, c=cap;
    while(dp[i][c]!=0)
    {
        if(dp[i][c]!=dp[i-1][c])
        {
            cout<<i+1<<" included" << endl;
            c=c - w[i];
        }
        i--;
    }

}

int BottomUp(int w[], int p[], int n, int cap)
{
    int dp[100][100];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=cap; j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;

            if(w[i]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],p[i]+dp[i-1][j-w[i]]);
            }
        }
    }
    Find(dp, w, n, cap);

    cout<<"Maximum profit is: "<<dp[n][cap]<<endl;
}

int main()
{

    int n,p[50],w[50],c;
    cout<<"Enter item number "<<endl;
    cin>>n;
    cout<<"Enter Weight and Profit"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
        cin>>p[i];
    }
    cout<<"Enter the max capacity "<<endl;
    cin>>c;

    BottomUp(w,p,n,c);

}
