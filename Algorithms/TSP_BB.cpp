#include <bits/stdc++.h>
#define arSize 5
using namespace std;
typedef struct valueIndex  valueIndex;
struct valueIndex
{
    int val;
    int index;
};

void printTheMatrix(int ar[arSize][arSize]);///prints a matrix
void copyTheMatrix(int ar1[arSize][arSize],int ar[arSize][arSize]);///to copy 1 matrix to another matrix
void makeDistance_matrix (int ar [arSize][arSize],int from, int to);///creates a distance matrix from one node to another node
void makeDistance_matrix_previous(int ar [arSize][arSize],int from, int to,int previous);
int reduce_matrix(int ar[arSize][arSize]);///reduces a matrix and returns the reduced value
int value_of_index (int ar[arSize][arSize],int row,int column);///returns a value form an index
valueIndex minimum_value_index  (int ar[]);///returns a minimum value and its index at the same time


void printTheMatrix(int ar[arSize][arSize])
{
    for(int i=0; i<arSize; i++)
    {
        for (int j = 0; j<arSize; j++)
        {
            if (ar[i][j]>9000&&ar[i][j]<=9999) /// 9999 as infinity
            {
                cout  <<"INF\t";
            }
            else
            {
                cout  <<ar[i][j] << "\t";
            }
        }
        cout<<endl;
    }
}

void copyTheMatrix(int ar1[arSize][arSize],int ar[arSize][arSize])
{
    for(int i=0; i<arSize; i++)
    {
        for (int j = 0; j<arSize; j++)
        {
            ar1[i][j]=ar[i][j];
        }
    }

}

void makeDistance_matrix (int ar [arSize][arSize],int from, int to)
{
    for(int i=0; i<arSize; i++)
    {
        for (int j = 0; j<arSize; j++)
        {
            if (i==from)
            {
                ar[i][j]=9999;
            }
            if (j==to)
            {
                ar[i][j]=9999;
            }
            if(j==from&&i==to)
            {
                ar[i][j]= 9999;
            }
        }
    }
}

void makeDistance_matrix_previous(int ar [arSize][arSize],int from, int to,int previous)
{
    for(int i=0; i<arSize; i++)
    {
        for (int j = 0; j<arSize; j++)
        {

            if (i==from)
            {
                ar[i][j]=9999;
            }
            if (j==to)
            {
                ar[i][j]=9999;
            }
            if(j==from&&i==to)
            {
                ar[i][j]= 9999;
            }
            if(j==previous&&i==to)
            {
                ar[i][j]=9999;
            }
        }
    }
}

int reduce_matrix(int ar[arSize][arSize])
{
    int mini=0;
    for  (int i = 0; i < arSize; i++)
    {
        int m = INT_MAX;
        for (int j = 0; j < arSize; j++)
        {
            if (ar[i][j] < m)
            {
                m = ar[i][j];
            }
        }
        if (m>9000&&m<=9999)///if all values of the row is infinity or close to infinity then the minimum value of the row will be 0.
        {
            m=0;
        }
        mini+=m;
        for (int j =0; j<arSize; j++)
        {
            ar[i][j]=ar[i][j]-m;
        }
    }
    for(int i=0; i<arSize; i++)
    {
        int m = INT_MAX;
        for (int j = 0; j<arSize; j++)
        {
            if (ar[j][i]<m)
            {
                m = ar[j][i];
            }
        }
        if (m>9000&&m<=9999)///if all values of the column is infinity or close to infinity then the minimum value of the column will be 0.
        {
            m=0;
        }
        mini+=m;
        for (int j =0; j<arSize; j++)
        {
            ar[j][i]=ar[j][i]-m;
        }
    }
    return mini;
}

int value_of_index (int ar[arSize][arSize],int row,int column)
{
    return ar[row][column];
}

valueIndex minimum_value_index  (int ar[])
{
    valueIndex v;
    v.val = INT_MAX;
    v.index = INT_MAX;
    for(int i = 1; i<arSize; i++)
    {
        if(ar[i]<v.val)
        {
            v.val=ar[i];
            v.index=i;
        }
    }
    return v;
}

int main ()
{
    valueIndex  v,v1;
    priority_queue <int, vector<int>, greater<int> > pq;///creating a minimum priority queue which will hold the smallest value on top.
    int ar[arSize][arSize], m[arSize],ar1[arSize][arSize],m2[arSize],ar2[arSize][arSize],ar3[arSize][arSize],m3[arSize];
    for(int i=0; i<arSize; i++)
    {
        for (int j = 0; j<arSize; j++)
        {
            cin >> ar[i][j];
        }
    }
    cout<<"\n***********Stage 1***********\n\n";
    m[0]= reduce_matrix(ar);
    cout << "\nMain reduced matrix :\n";
    printTheMatrix(ar);
    cout << "\nTotal minimum values  :" << m[0] <<endl;

    cout << endl;
    for (int i = 1; i<arSize; i++)
    {
        copyTheMatrix (ar1,ar);
        cout << "\n\n1-->" << i+1 <<endl;
        makeDistance_matrix(ar1,0,i);
        printTheMatrix(ar1);
        m[i]=m[0]+reduce_matrix(ar1)+value_of_index(ar,0,i);
        cout << "Cost of 1-->"<< i+1 << " is :" << m[i] <<endl;
    }

    v = minimum_value_index(m);
    cout << "\nSmallest path for 1st stage is : 1" << "-->" << v.index+1 <<" is "<<v.val<<endl;
    cout<<"\n***********Stage 2***********\n";
    copyTheMatrix (ar1,ar);
    makeDistance_matrix(ar1,0,v.index);
    cout << "Stage 2 parent matrix:\n1--->4\n";
    printTheMatrix(ar1);

    copyTheMatrix(ar2,ar1);
    makeDistance_matrix_previous(ar2,v.index,1,0);
    cout <<endl;
    cout << "4-->2\n";
    printTheMatrix(ar2);
    m2[0]=value_of_index(ar1,v.index,1)+m[0]+reduce_matrix(ar2);
    cout<<"Cost of 4-->2 :"<<m2[0]<<endl;
    pq.push(m2[0]);

    copyTheMatrix(ar2,ar1);
    makeDistance_matrix_previous(ar2,v.index,2,0);
    cout << endl;
    cout << "4-->3\n";
    printTheMatrix(ar2);
    m2[1]=value_of_index(ar1,v.index,2)+m[0]+reduce_matrix(ar2);
    cout<<"Cost of 4-->3 : "<<m2[1]<<endl;
    pq.push(m2[1]);

    copyTheMatrix(ar2,ar1);
    makeDistance_matrix_previous(ar2,v.index,4,0);
    cout << endl;
    cout << "4-->5\n";
    printTheMatrix(ar2);
    m2[2]=value_of_index(ar1,v.index,4)+m[0]+reduce_matrix(ar2);
    cout<<"Cost of 4-->5:"<<m2[2]<<endl;
    pq.push(m2[2]);

    cout << "The minimum value of the 2nd stage is  4-->2 :"<<pq.top()<<endl;

    while (!pq.empty())
    {
        pq.pop();///emptying the queue to reuse it
    }

    cout<<"\n***********Stage 3***********";
    copyTheMatrix(ar2,ar1);
    makeDistance_matrix_previous(ar2,v.index,1,0);
    cout << "\nStage 3 parent matrix:\n4--->2\n";
    printTheMatrix(ar2);

    copyTheMatrix(ar3,ar2);
    makeDistance_matrix_previous(ar3,1,2,0);
    cout << "\n2-->3\n";
    printTheMatrix(ar3);
    m3[0]=m2[0]+reduce_matrix(ar3)+value_of_index(ar2,1,2);
    cout<<"Cost of 2-->3:"<<m3[0]<<endl;
    pq.push(m3[0]);

    copyTheMatrix(ar3,ar2);
    makeDistance_matrix_previous(ar3,1,4,0);
    cout << "\n2-->5\n";
    printTheMatrix(ar3);
    m3[1]=m2[0]+reduce_matrix(ar3)+value_of_index(ar2,1,4);
    cout<<"Cost of 2-->5:"<<m3[1]<<endl;
    pq.push(m3[1]);

    cout << "The minimum value of the 3rd stage is  2-->5 :"<<pq.top()<<endl;
    return 0;
}
/**input*

9999 20 30 10 11
15 9999 16 4 2
3 5 9999 2 4
19 6 18 9999 3
16 4 7 16 9999

**/
