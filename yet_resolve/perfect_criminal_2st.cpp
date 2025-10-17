#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    vector<vector<char>> dp(n, vector<char>(m, 0));
    dp[0][0] = 1;
    for (auto &x : info)
    {
        int a = x[0], b = x[1];
        for (int A = n - 1 - a; A >= 0; --A)
            for (int B = m - 1 - b; B >= 0; --B)
                if (dp[A][B])
                    dp[A + a][B + b] = 1;
    }
    int best = INT_MAX;
    for (int A = 0; A < n; ++A)
        for (int B = 0; B < m; ++B)
            if (dp[A][B])
                best = min(best, A);
    return best == INT_MAX ? -1 : best;
}

int main()
{

    vector<vector<int>> info = {{1, 2}, {2, 3}, {2, 1}};
    int n = 1, m = 7;
    int result;
    result = solution(info, n, m);

    cout << result;
}