#include<bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{

    int noOfProcesses, noOfResources,temp=0,h=0,timesOfChecking=0;
    cout<<"Enter the no. of Processes:";
    cin>>noOfProcesses;
    cout<<endl;
    cout<<"Enter the no. Resources:";
    cin>>noOfResources;
    cout<<endl;

    int allocation[noOfProcesses][noOfResources],
    completed[noOfProcesses],
    check[noOfProcesses],
    need[noOfProcesses][noOfResources],
    result[noOfProcesses],
    Max[noOfProcesses][noOfResources],
    available[noOfResources];


    memset(completed, 0, sizeof(completed));
    memset(check, 0, sizeof(check));

    for(int i=0; i<noOfProcesses; ++i)
    {
        cout<<"Process "<<i+1<<": "<<endl;
        for(int j=0; j<noOfResources; j++)
        {
            cout<<"Maximum value for resource "<<j+1<<": ";
            cin>>Max[i][j];
        }
        for(int j=0; j<noOfResources; j++)
        {
            cout<<"Allocated value for resource "<<j+1<<": ";
            cin>>allocation[i][j];
            need[i][j]=Max[i][j]-allocation[i][j];
        }

    }
    cout<<endl;

    for(int i=0; i<noOfResources; i++)
    {
        cout<<"Enter total value of resource "<<i+1<<": ";
        cin>>available[i];
    }

    for(int i=0; i<noOfResources; i++)
    {
        for(int j=0; j<noOfProcesses; j++)
        {
            temp+=allocation[j][i];
        }
        available[i]-=temp;
        temp=0;
    }
    cout<<endl;

   while( h!=noOfProcesses && timesOfChecking<noOfProcesses)
    {
        for(int i=0; i<noOfProcesses; i++)
        {

            if(completed[i]==0)
            {

                for(int j=0; j<noOfResources; j++)
                {
                    if(need[i][j]>available[j])
                    {
                        check[i]=1;
                    }
                }


                if(check[i]==0)
                {
                    for(int k=0; k<noOfResources; k++)
                    {
                        available[k]+=allocation[i][k];
                    }
                    completed[i]=1;
                    result[h]=i;

                    h++;

                }
            }
            if(completed[i]==0)
                check[i]=0;
        }
        timesOfChecking++;
    }

    cout<<"Program Output:"<<endl;
    cout<<endl;

    if(timesOfChecking<=noOfProcesses)
    {
        cout<<"The System is currently in safe state and <";
        for(int i=0; i<noOfProcesses; i++)
        {
            cout<<"  P"<<result[i]+1;
        }
        cout<<" > is the safe sequence."<<endl;

    }
    else
        cout<<"There is no safe state.";
    return 0;
}
