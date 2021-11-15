#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, temp , tt=0, min_, x, i, j;
    float total_tt=0, total_wt=0;

    printf("Enter Process Number: ");
    scanf("%d",&n);

    int arr[n][6];

    for(int i=0; i<n; i++)
    {
        arr[i][0]=i;
        arr[i][3]=0;
        arr[i][4]=0;
        arr[i][5]=0;

    }

    cout<<"\nEnter CPU Times:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][2];
    }
    cout<<"\nEnter the arrival times:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][1];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i][2] > arr[j][2])
            {
                temp =arr[i][1];
                arr[i][1]=arr[j][1];
                arr[j][1]=temp;

                temp =arr[i][2];
                arr[i][2]=arr[j][2];
                arr[j][2]=temp;
            }
        }
    }

    min_ = arr[0][1];
    for(int i=0; i<n; i++)
    {
        if(min_> arr[i][1])
        {
            min_=arr[i][1];
            x = i;
        }
    }
    tt = min_;
    arr[x][5]=tt + arr[x][2];
    tt=arr[x][5];

    for(int i=0; i<n; i++)
    {
        if(arr[i][1]!= min_)
        {
            arr[i][5] = arr[i][2]+tt;
            tt = arr[i][5];
        }
    }

    for(int i=0; i<n; i++)
    {
        arr[i][4]=arr[i][5]-arr[i][1];
        total_tt=total_tt+arr[i][4];
        arr[i][3]=arr[i][4]-arr[i][2];
        total_wt+=arr[i][3];

        cout<<"\nProcess "<<i+1<<": waiting time :"<<arr[i][3]<<" Turnaround time :"<<arr[i][4]<<endl;
    }
    cout<<"\nAverage Waiting time: "<<total_wt/n<<endl;
    cout<<"\nAverage Turnaround time: "<<total_tt/n<<endl;

}
