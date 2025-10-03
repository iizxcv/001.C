#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>

using namespace std;
// 깊이, 방문현황, 누적값을 튜플로 묶자
int dfs_permunante(vector<int> &arr)
{

    int n = arr.size();
    int cnt = 0;
    int ans = 0;
    vector<tuple<int, vector<bool>, int, int>> stack;

    for (int i = 0; i < n; i++)
    {
        vector<bool> init_visited(n, false);
        init_visited[i] = true;
        stack.push_back({1, init_visited, 0, i});
    }

    while (!stack.empty())
    {
        if (n == get<0>(stack.back()))
        {
            ans = max(ans, get<2>(stack.back()));
            stack.pop_back();
            continue;
        }
        tuple<int, vector<bool>, int, int> a = stack.back();
        int deeps = get<0>(a);
        vector<bool> visited = get<1>(a);
        int sum = get<2>(a);
        int prev = get<3>(a);
        stack.pop_back();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int ret = sum + abs(arr[prev] - arr[i]);
                visited[i] = true;
                stack.push_back({deeps + 1, visited, ret, i});
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> numbers(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << dfs_permunante(numbers);
}