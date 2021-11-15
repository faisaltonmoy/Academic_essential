#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    float total_tt=0, total_wt=0;

    printf("Enter Process Number: ");
    scanf("%d",&n);

    int arr[n][8];
    int track_completed[100];
    memset(track_completed,0,sizeof(track_completed));

    for(int i=0; i<n; i++)
    {
        arr[i][0]=i;
        arr[i][3]=0;
        arr[i][5]=0;
        arr[i][6]=0;
        arr[i][7]=0;

    }

    cout<<"\nEnter CPU Times:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][2];
        arr[i][4]=arr[i][2];
    }
    cout<<"\nEnter the arrival times:\n"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][1];
    }

    int current_time = 0;
    int completed = 0;

    while(completed != n) {
        int x = -1;
        int min_ = 1000000;
        for(int i = 0; i < n; i++) {
            if(arr[i][1] <= current_time && track_completed[i] == 0) {
                if(arr[i][4] < min_) {
                    min_ = arr[i][4];
                    x = i;
                }
            }
        }

        if(x != -1) {
            if(arr[x][4] == arr[x][2]) {
                arr[x][3] = current_time;
            }
            arr[x][4] -= 1;
            current_time++;

            if(arr[x][4] == 0) {
                arr[x][7] = current_time;
                arr[x][6] = arr[x][7] - arr[x][1];
                arr[x][5] = arr[x][6] - arr[x][2];


                total_tt += arr[x][6];
                total_wt += arr[x][5];

                track_completed[x] = 1;
                completed++;
            }
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
