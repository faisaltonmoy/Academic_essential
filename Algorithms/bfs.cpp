#include<bits/stdc++.h>
using namespace std;
int n,e;
int root[100];
int level[100];
vector<int>Vlist[100];
queue<int>q;
void BFS(int s)
{
    root[s]=1;
    level[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int j=0; j<Vlist[x].size(); j++)
        {
            int New=Vlist[x][j];
            if(root[New]==1)
            {
                level[New]=level[x]+1;
                root[New]=x;
                q.push(New);
            }
        }
    }
}
int main()
{
    printf("ENTER THE NODE:\n");
    scanf("%d",&n);
    printf("ENTER THE EDGE:\n");
    scanf("%d",&e);
    int x,y;
    for(int i=1; i<=e; i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        Vlist[x].push_back(y);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<Vlist[i].size(); j++)
        {
            printf("%d ",Vlist[i][j]);
        }
    }
    BFS(1);

    return 0;
}
