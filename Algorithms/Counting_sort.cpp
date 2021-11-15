#include<bits/stdc++.h>
using namespace std;

#define n 10
#define k 10
void counting(int A[], int B[])
{
    int C[k+1];
    for(int i = 0; i <= k; i++)
    {
        C[i] = 0;
    }
    for(int j = 1; j <= n; j++)
    {
        C[A[j]] += 1;
    }
    for (int i = 1; i <= k; i++)
    {
        C[i] = C[i] + C[i-1];
    }
    for(int j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] -= 1;
    }
}
int main()
{
    int A[n+1];
    int B[n+1];
    srand(time(NULL));
    for(int i = 1; i <= n; i++)
    {
        A[i] = rand() % 10;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;
    counting(A, B);
    for(int i = 1; i <= n; i++)
    {
        cout << B[i] << "\t";
    }
    cout << endl;

    return 0;
}
