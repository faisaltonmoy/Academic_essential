#include <bits/stdc++.h>

using namespace std;

int res [100], val[100];

void S_O_S (int currentSum, int index, int sum, int len)
{
    if(currentSum == sum)
    {

        for(int i = 0; i < len; i++)
        {
            if(res[i]==1)
            {
                cout << val[i] <<" ";
            }
        }
        cout<<endl;
    }

    else if (index == len)
    {
        return;
    }

    else
    {
        res[index] = 1;
        currentSum += val[index];
        S_O_S(currentSum, index + 1, sum,len);
        currentSum -= val[index];
        res[index] = 0;
        S_O_S(currentSum, index + 1, sum,len);
    }

}

int main ()
{

    int cap,len;
    cout<<"How many values: ";
    cin>>len;
    cout<<"Enter  values: ";

    for(int i =0; i<len ; i++)
    {
        cin>>val[i];
    }

    sort(val, val+len);

    cout<<"Enter sum capacity : ";
    cin>>cap;

    S_O_S(0,0,cap,len);

    return 0;

}
//10 5 18 15 13 12
