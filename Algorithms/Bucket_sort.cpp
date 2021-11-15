#include<bits/stdc++.h>
using namespace std;

void bucket(double ar1[])
{
    int n=10;
    vector<double> ar2[n];

    for(int i=0; i<n; i++)
    {
        int index=n*ar1[i];
        ar2[index].push_back(ar1[i]);
    }
    for(int i=0; i<n; i++)
    {
        sort(ar2[i].begin(),ar2[i].end());
    }
    int i=0;
    for(int j=0; j<n; j++)
    {

        for(int k=0; k<ar2[j].size(); k++)
        {
            ar1[i++]=ar2[j][k];
        }
    }
}
// .25 .15 .02 .36 .59 .45 .85 .19 .97 .85
int main()
{
    int n;
    cout<<"Array Size ";
    cin>>n;

    double ar[n];
    cout<<"Enter array between (0-1)\n";
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout<<"Unsorted array"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<"\t";
    }
    cout << endl;

    bucket(ar);

    cout << endl;
    cout<<"Sorted array"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<"\t";
    }
    cout << endl;
    return 0;
}
