#include<bits/stdc++.h>
using namespace std;

vector < int > graph[100];
int visited[100];

#define WHITE 0
#define GRAY 1
#define BLACK 2

bool cycle;

vector < int > res;

void dfs(int s)
{

    visited[s] = GRAY;
    sort(graph[s].begin(), graph[s].end());

    for (int i = graph[s].size() - 1; i >=0 ; i--)
    {
        int next = graph[s][i];
        if (visited[next] == WHITE)
        {
            dfs(next);
        }
        else if (visited[next]==GRAY)
        {
            cycle =true;
            return ;
        }

    }
    visited[s] = BLACK;
    res.push_back(s);
}

int main()
{
    cycle = false;
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n ;
    cout << "Enter number of edges: ";
    cin >> e ;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = n; i >= 1; i--)
    {
        if (visited[i] == WHITE)
            dfs(i);
    }

    if(cycle == true)
        cout<<"This is a Cyclic Graph.";
    else
    {
        reverse(res.begin(), res.end());
        cout << "Topological Sort: ";
        for (int i = 0 ; i < res.size(); i++)
        {
            cout << res[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
