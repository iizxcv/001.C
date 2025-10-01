#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <deque>
using namespace std;

void DFS(vector<vector<int>> *g, int start)
{
    vector<int> visited(g->size(), 0);
    vector<int> stack;
    stack.push_back(start);
    while (!stack.empty())
    {
        int cur = stack.back();
        stack.pop_back();
        if (visited[cur])
            continue;

        cout << cur << " ";

        visited[cur] = 1;
        for (int i = g->size() - 1; i > 0; i--)
        {
            if ((*g)[cur][i] == 1) //&& find(stack.begin(), stack.end(), i) == stack.end()
            {
                stack.push_back(i);
            }
        }
    }
}

void BFS(vector<vector<int>> *g, int start)
{
    vector<int> visited(g->size(), 0);
    deque<int> queue;
    queue.push_back(start);

    while (!queue.empty())
    {
        int cur = queue.front();
        queue.pop_front();

        if (visited[cur] == 1)
            continue;

        cout << cur << " ";
        visited[cur] = 1;

        for (int i = 1; i < g->size() + 1; i++)
        {
            if ((*g)[cur][i] == 1)
            {
                queue.push_back(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1][v2] = 1;
        g[v2][v1] = 1;
    }

    // for (int i = 1; i < n + 1; i++)
    // {
    //     for (int j = 1; j < n + 1; j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    DFS(&g, v);
    cout << "\n";
    BFS(&g, v);
}