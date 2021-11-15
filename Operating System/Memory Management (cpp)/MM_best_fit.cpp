#include<bits/stdc++.h>
using namespace std;
int ex_frag = 0;

void bestFit(int blockSize[], int m,int processSize[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for(int i =0;i<n;i++)
    {
        int bestInd=-1;
        for(int j =0;j<m;j++)
        {
            if(blockSize[j]>=processSize[i])
            {
                if(bestInd==-1)
                {
                    bestInd=j;
                }
                else if (blockSize[bestInd]>blockSize[j])
                {
                    bestInd=j;
                }
            }
        }
        if(bestInd!=-1)
        {
            allocation[i]=bestInd;
            blockSize[bestInd]-=processSize[i];
        }
        if(allocation[i]!=-1)
        {
            for(int k=0; k<m; k++)
            {
                cout<<blockSize[k]<<" \t";
            }
            cout<<endl;

        }
        else {
            for(int k=0; k<m; k++)
            {
                ex_frag+=blockSize[k];
            }
            cout<<"Not Allocated"<<endl;
            break;
        }
    }
}


int main()
{
    int m,n;
    cout<<"Enter number of blocks and process: ";
    cin>>m>>n;
    int blockSize[m],processSize[n];
    cout<<endl<<"Memory Holes : ";
    for(int i=0; i<m; i++)
    {
        cin>>blockSize[i];
    }
    cout<<endl<<"Memory Request : ";
    for(int i=0; i<n; i++)
    {
        cin>>processSize[i];
    }
    cout<<"\n\t    Best  Fit     \t\n"<<endl;
    bestFit(blockSize, m, processSize, n);
    if(ex_frag == 0)
    {
        cout<<"\n    No External Fragmentation"<<endl;
    }else
    {
        cout<<"\nExternal Fragmentation: "<<ex_frag<<endl;
    }


    return 0 ;
}

