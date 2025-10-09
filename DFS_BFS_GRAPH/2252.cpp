#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<vector<int>, int>> nodes;
    // nodes.push_back(make_tuple(vector<int>(),0));
    for (int i = 0; i < n + 1; i++)
    {
        nodes.push_back(make_tuple(vector<int>(), 0));
    }

    for (int i = 0; i < m; i++)
    {
        int E, V;
        cin >> E >> V;

        get<0>(nodes[E]).push_back(V);
        get<1>(nodes[V])++;
    }

    deque<int> queue;
    vector<int> ans;
    for (int i = 1; i < n + 1; i++)
    {
        if (get<1>(nodes[i]) == 0)
        {
            queue.push_back(i);
        }
    }

    while (!queue.empty())
    {
        int cur_node = queue.front();
        queue.pop_front();

        ans.push_back(cur_node);

        for (auto v : get<0>(nodes[cur_node]))
        {
            get<1>(nodes[v])--;

            // cout << v << "\n";
            // int v = get<1>(nodes[cur_node]);
            // get<0>(nodes[v]) -= 1;

            if (get<1>(nodes[v]) == 0)
            {
                queue.push_back(v);
            }
        }
    }
    for (auto answer : ans)
    {
        cout << answer << "\n";
    }
}