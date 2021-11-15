#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,i,val = 0,remain = 0;
    float total_tt=0, total_wt=0;

    printf("Enter Process Number: ");
    scanf("%d",&n);

    int arr[n][9];
    int track[100];
    memset(track,0,sizeof(track));

    for(i=0; i<n; i++)
    {
        arr[i][0]=i;  //Process Time
        arr[i][4]=0;  //Start Time
        arr[i][5]=0;  //Remaining Time
        arr[i][6]=0;  //Waiting Time
        arr[i][7]=0;  //Turnaround Time
        arr[i][8]=0;  //Compilation Time

    }

    cout<<"\nEnter CPU Times:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][2];
        arr[i][5]=arr[i][2];
    }
    cout<<"\nEnter the arrival times:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][1];
    }
    cout<<"\nEnter the Priority:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][3];
    }

    while(remain != n)
    {
        int x = -1;
        int find_min = 1000000;
        for(i = 0; i < n; i++)
        {
            if(arr[i][1] <= val && track[i] == 0)
            {
                if(arr[i][3] < find_min)
                {
                    find_min = arr[i][3];
                    x = i;
                }
            }
        }

        if(x != -1)
        {
            if(arr[x][5] == arr[x][2])
            {
                arr[x][4] = val;
            }
            arr[x][5] -= 1;
            val++;

            if(arr[x][5] == 0)
            {
                arr[x][8] = val;
                arr[x][7] = arr[x][8] - arr[x][1];
                arr[x][6] = arr[x][7] - arr[x][2];


                total_tt += arr[x][7];
                total_wt += arr[x][6];

                track[x] = 1;
                remain++;
            }
        }
    }


    for(int i=0; i<n; i++)
    {
        cout<<"\nProcess "<<i+1<<": waiting time :"<<arr[i][6]<<" Turnaround time :"<<arr[i][7]<<endl;
    }
    cout<<"\nAverage Waiting time: "<<total_wt/n<<endl;
    cout<<"\nAverage Turnaround time: "<<total_tt/n<<endl;

    return 0;

}

