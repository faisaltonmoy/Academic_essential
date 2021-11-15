#include <bits/stdc++.h>
#define inf 999

using namespace std;

int adjMat[100][100];
int par[100][100];

int path(int src , int dest)
{
    if(src==dest)
    {
        cout<<"path: "<<src;
        return 0;
    }
    path(src,par[src][dest]);
    cout<<" "<<dest;
}

int main()
{
    ifstream input("ex.txt");
    if(!input.is_open())
    {
        cout<<"File is not open"<<endl;
    }
    int n,n1,n2,w;
    input>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)
                adjMat[i][j]=0;
            else
                adjMat[i][j]=inf;
            par[i][j]=i;
        }
    }

    while(input>>n1>>n2>>w)
    {
        adjMat[n1][n2]=w;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
          cout<<adjMat[i][j]<<"  ";
        }
        cout<<endl;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(adjMat[i][k]+adjMat[k][j] < adjMat[i][j])
                {
                    adjMat[i][j] = adjMat[i][k]+adjMat[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }

    int src,dest;
    cout<<"\nEnter source and destination: ";
    cin>>src>>dest;

    cout<<"Cost: "<<adjMat[src][dest];
    cout<<endl;

    path(src,dest);

}
