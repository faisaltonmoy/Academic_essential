#include<bits/stdc++.h>
using namespace std;

vector < int > graph[105];
bool visited[105];

vector < int > res;

void dfs(int s)
{

    visited[s] = 1;
    for (int i = 0; i < graph[s].size(); i++)
    {
        int next = graph[s][i];
        if (visited[next] == 0)
            dfs(next);
    }
    res.push_back(s);
}

int main()
{
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

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    reverse(res.begin(), res.end());
    cout << "Topological Sort: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}
