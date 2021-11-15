#include <bits/stdc++.h>
using namespace std;
int b[100][100],c[100][100];
string X,Y;
#define diagonal_arrow 0
#define top_arrow 1
#define left_arrow 2
int length1,length2;
void Lcs_Length(int m, int n);
void print_LCS(string S,int i,int j);

void Lcs_Length(int m, int n)
{

    for(int i =0; i<m; i++)
    {
        c[i][0]=0;
    }
    for(int j =0; j <n; j++)
    {
        c[0][j]=0;
    }

    for(int i =0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(X[i]==Y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j] = diagonal_arrow;
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]= top_arrow;
            }
            else
            {
                c[i][j]= c[i][j-1];
                b[i][j]=left_arrow;
            }
        }
    }
}
void print_LCS(string S,int i,int j)
{
    if(i==0||j==0)
    {
        return;
    }
    if(b[i][j]==diagonal_arrow)
    {
        print_LCS(S,i-1,j-1);
        cout<<S[i];
    }
    else if(b[i][j]==top_arrow)
    {
        print_LCS(S,i-1,j);
    }
    else
    {
        print_LCS(S,i,j-1);
    }
}
int main()
{
    cout<<"Enter 1st String: ";
    cin>>X;
    cout<<"Enter 2nd String: ";
    cin>>Y;

    X= "0"+X;
    Y= "0"+Y;

    length1=X.length();
    length2=Y.length();

    Lcs_Length(length1,length2);

    cout<<"\nArrow Table: \n";
    for(int i=0; i<length1; i++)
    {
        for (int j = 0; j<length2; j++)
        {
            if(i==0||j==0)
            {
                cout<<"0\t";
            }
            else
            {
                if(b[i][j]==top_arrow)
                {
                    cout<<"top\t";
                }
                if(b[i][j]==left_arrow)
                {
                    cout<<"left\t";
                }
                if(b[i][j]==diagonal_arrow)
                {
                    cout<<"match\t";
                }
            }
        }
        cout<<endl;
    }
    cout<<"\nLength Table: \n";
    for(int i=0; i<length1; i++)
    {
        for (int j = 0; j<length2; j++)
        {
            cout<<c[i][j]-1<<"\t";
        }
        cout<<endl;
    }
    cout <<"\nlongest common length :";
    cout<< (c[length1-1][length2-1])-1<<endl;

    cout <<"\nlongest common subsequence :";
    print_LCS(X,length1,length2);
    cout<<endl;

    return 0;

}


