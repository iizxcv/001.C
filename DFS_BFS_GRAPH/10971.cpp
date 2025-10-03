#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 99999999;

int saler_traversal(vector<vector<int>> &w, vector<bool> &visited, int cur_node, int visited_cnt, int cost, int n)
{
    if (visited_cnt == n)
    {
        // 반드시 출발점(0)으로 돌아올 수 있는 경로가 있는지 확인
        if (w[cur_node][0] != 0)
            return cost + w[cur_node][0];
        else
            return INF;
    }
    int result = INF;
    for (int next_node = 0; next_node < n; next_node++)
    { // 반복 구간 수정!
        if (!visited[next_node] && w[cur_node][next_node] != 0)
        {
            visited[next_node] = true;
            result = min(result, saler_traversal(w, visited, next_node, visited_cnt + 1, cost + w[cur_node][next_node], n));
            visited[next_node] = false;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> nodes(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // j < n으로 수정
        {
            cin >> nodes[i][j];
        }
    }
    vector<bool> visited(n, false);
    visited[0] = true; // 시작점 방문 체크!
    int ans = saler_traversal(nodes, visited, 0, 1, 0, n);
    cout << (ans == INF ? 0 : ans);
}

/*
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0
*/
