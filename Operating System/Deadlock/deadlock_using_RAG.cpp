#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int MAX =  100;
vector<int> graph[MAX];
int color[MAX],parent[MAX];
bool cycle = 0;
string str[MAX],u,v;


void dfs_get_path(int cur,int tar)
{
    if(cur==tar)
    {
        cout<<str[cur]<<" ";
        return;
    }
    dfs_get_path(parent[cur],tar);
    cout<<str[cur]<<" ";
}

void dfs_find_cycle(int node)
{
    color[node]  = GRAY;
    for(int i=0;i<graph[node].size();i++)
    {
        if(color[graph[node][i]]==WHITE)
        {
            parent[graph[node][i]] = node;
            dfs_find_cycle(graph[node][i]);
        }
        else if(color[graph[node][i]]==GRAY)
        {
            cycle = 1;
            cout<<"Deadlock Is Present Among nodes: ";
            dfs_get_path(node,graph[node][i]);
            cout<<endl;
        }
    }
    color[node]= BLACK;
}
int main()
{
    int n,e;
    cout<<"Enter number of nodes : ";
    cin>>n;

    cout<<"Enter number of edges : ";
    cin>>e;

    freopen("deadlock.txt", "r", stdin);

    map<string,int> nodeList;
    for(int i=1; i<=n; i++)
    {
        cin>>str[i];
        nodeList[str[i]]  = i;
    }

     for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        graph[nodeList[u]].push_back(nodeList[v]);
    }

    for(int i=1;i<=n;i++)
    {
        if(color[i]==WHITE)
        {
            parent[i]  = i;
            dfs_find_cycle(i);
        }
    }
    if(!cycle)
    {
        cout<<"No Deadlock Found"<<endl;
    }
    return 0;
}



