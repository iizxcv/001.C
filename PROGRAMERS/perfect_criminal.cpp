#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    // 깊이(i),A누적, B누적,
    stack<tuple<int, int, int>> stk;
    int answer = max(n, m);

    stk.push({0, 0, 0});
    while (!stk.empty())
    {
        auto [depth, a, b] = stk.top();
        stk.pop();
        if (depth == info.size())
        {
            answer = min(answer, a);
            continue;
        }

        if (b + info[depth][1] < m)
        {
            stk.push({depth + 1, a, b + info[depth][1]});
        }
        if (a + info[depth][0] < n)
        {
            stk.push({depth + 1, a + info[depth][0], b});
        }

        // a > n; b > m;
    }

    return answer == max(n, m) ? -1 : answer;
}

int main()
{

    vector<vector<int>> info = {{1, 2}, {2, 3}, {2, 1}};
    int n = 1, m = 7;
    int result;
    result = solution(info, n, m);

    cout << result;
}