#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void virus_diffusion(vector<vector<int>> *nds, vector<int> *vst)
{
    int count = 0;
    vector<int> stack;
    stack.push_back(1);
    (*vst)[1] = 1;
    while (!stack.empty())
    {
        int a = stack.back();
        stack.pop_back();
        for (int i = (*nds).size() - 1; i > 0; i--)
        {
            if ((*nds)[a][i] == 1 && (*vst)[i] != 1)
            {
                int node = i;
                stack.push_back(node);
                (*vst)[i] = 1;
            }
        }
        count++;
    }
    cout << count - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> nodes(n + 1, (vector<int>(n + 1, 0)));

    for (int i = 0; i < m; i++)
    {
        int V, E;
        cin >> V >> E;
        nodes[V][E] = 1;
        nodes[E][V] = 1;
    }
    vector<int> visited(n + 1, 0);

    virus_diffusion(&nodes, &visited);
}