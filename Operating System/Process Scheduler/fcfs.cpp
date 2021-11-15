#include <iostream>
using namespace std;

int main()
{
    int temp,n;

    cout<<"Enter Process Number: ";
    cin>>n;

    int arr[n][5];

    for(int i=0; i<n; i++)
    {
        arr[i][0]=i;
        arr[i][3]=0;
        arr[i][4]=0;
    }


    cout<<"\nEnter CPU Times: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][2];
    }
    cout<<"\nEnter the arrival times: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i][1];
    }

    int temp_wt=0;
    float wt=0;
    float tt=0;

    for(int i=0; i<n; i++)
    {

        int min_=0;
        int temp_sort=arr[min_][1];
        for(int j=0; j<n; j++)
        {
            if(temp_sort>arr[j][1])
            {
                min_=j;

                temp_sort=arr[j][1];

            }
        }
        arr[min_][3]=temp_wt;
        arr[min_][3]=arr[min_][3]-arr[min_][1];
        wt+=arr[min_][3];

        temp_wt+=arr[min_][2];

        arr[min_][4]=temp_wt;
        arr[min_][4]=arr[min_][4]-arr[min_][1];
        tt+=arr[min_][4];

        arr[min_][1]=9999;

    }
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Process "<<i+1<<": waiting time :"<<arr[i][3]<<" Turnaround time :"<<arr[i][4]<<endl;
    }
    cout<<endl;
    cout<<"Average Waiting time: "<<wt/n<<endl;
    cout<<"Average Turnaround time: "<<tt/n<<endl;

}
