#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
int v,m;
int root[100];
int colour[100];
vector<int>vlist[100];
void DFS_Visit(int u, int v)
{
    colour[u] = GRAY;

    for(int i = 0 ; i<vlist[u].size() ; i++)
    {

        int New =vlist[u][i];
        if(colour[New] == WHITE)
        {
            root[New] = u;
            DFS_Visit(New, v);
        }
    }
    colour[u] = BLACK;

    printf("%d ",u);
}
void DFS(int v)
{
    for(int i = 0 ; i < v ; i++)
        colour[i] = WHITE;

    for(int i = 0 ; i<v ; i++)
    {
        if(colour[i] == WHITE)
        {
            DFS_Visit(i, v);
        }
    }
}

int main()
{
    printf("ENTER THE  Vertex:\n");
    scanf("%d",& v);
    printf("ENTER THE EDGE:\n");
    scanf("%d",&m);
    int x,y;
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        vlist[x].push_back(y);
    }
    for(int i=1; i<=  v; i++)
    {
        printf("\n");
        for(int j=0; j<vlist[i].size(); j++)
        {
            printf("%d",vlist[i][j]);
        }
    }
    DFS(v);

}

// R A A S C S W F F S D S U D G U V G E V D T B T T E
