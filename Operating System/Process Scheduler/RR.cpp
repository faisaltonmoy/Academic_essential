#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,temp,tq;
    float total_tt=0, total_wt=0;

    printf("Enter Process Number: ");
    scanf("%d",&n);

    int arr[n][6];

    for(int i=0; i<n; i++)
    {
        arr[i][0]=i;
        arr[i][4]=0;
        arr[i][5]=0;
    }

    cout<<"\nEnter CPU Times:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][2];
        arr[i][3]=arr[i][2];
    }
    cout<<"\nEnter the arrival times:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][1];
    }
    cout<< "\nEnter time Quantum: ";
    cin >>tq;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i][1] > arr[j][1])
            {
                temp =arr[i][1];
                arr[i][1]=arr[j][1];
                arr[j][1]=temp;

                temp =arr[i][3];
                arr[i][3]=arr[j][3];
                arr[j][3]=temp;
            }
        }
    }

    int i,x,current_time = 0;
    int completed = 0;
    int track = 0;

    while(true)
    {
        for(i=0,track=0; i<n; i++)
        {
            temp=tq;
            if(arr[i][3]==0)
            {
                track++;
                continue;

            }
            if(arr[i][3]>tq)
            {
               arr[i][3]=arr[i][3] - tq;
            }
            else
            {
                if(arr[i][3] >= 0)
                {
                    temp=arr[i][3];
                    arr[i][3]=0;
                }
            }
            current_time=current_time+temp;
            arr[i][5]=current_time-arr[i][1];
        }
        if(n==track)
        {
            break;
        }
    }

    for(int i=0; i<n; i++)
    {
        total_tt += arr[i][5];
        arr[i][4] = arr[i][5] - arr[i][2];
        total_wt += arr[i][4];
        cout<<"\nProcess "<<i+1<<": waiting time :"<<arr[i][4]<<" Turnaround time :"<<arr[i][5]<<endl;

    }
    cout<<"\nAverage Waiting time: "<<total_wt/n<<endl;
    cout<<"\nAverage Turnaround time: "<<total_tt/n<<endl;

    return 0;

}

//10 5 4 15 2
