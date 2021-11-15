#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,i,val = 0,remain = 0;
    float total_tt=0, total_wt=0;

    printf("Enter Process Number: ");
    scanf("%d",&n);

    int arr[n][8];
    int track[100];
    memset(track,0,sizeof(track));

    for(i=0; i<n; i++)
    {
        arr[i][0]=i;  //Process Time
        arr[i][5]=0;  //Waiting Time
        arr[i][6]=0;  //Turnaround Time
        arr[i][7]=0;  //Compilation Time

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
    cout<<"\nEnter the Priority:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][3];
    }

 while(remain != n) {
        int x = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i][1] <= val && track[i] == 0) {
                if(arr[i][3] > mx) {
                    mx = arr[i][3];
                    x = i;
                }
                if(arr[i][3] == mx) {
                    if(arr[i][1] < arr[x][1]) {
                        mx = arr[i][3];
                        x = i;
                    }
                }
            }
        }
        if(x != -1) {
            arr[x][5]=val;
            arr[x][5]=arr[x][5]-arr[x][1];
            total_wt+=arr[x][5];

            val+=arr[x][2];

            arr[x][6]=val;
            arr[x][6]=arr[x][6]-arr[x][1];
            total_tt+=arr[x][6];


            track[x] = 1;
            remain++;

        }
        else {
            val++;
        }

    }


    for(int i=0; i<n; i++)
    {
        cout<<"\nProcess "<<i+1<<": waiting time :"<<arr[i][5]<<" Turnaround time :"<<arr[i][6]<<endl;
    }
    cout<<"\nAverage Waiting time: "<<total_wt/n<<endl;
    cout<<"\nAverage Turnaround time: "<<total_tt/n<<endl;

    return 0;

}


