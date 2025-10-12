#include <iostream>
#include <vector>
using namespace std;

int func1(vector<vector<int>> &DP, int ii, int jj)
{
    if (DP[ii][jj] != 0)
    {
        return DP[ii][jj];
    }

    auto &it = DP[ii][jj];

    return it = func1(DP, ii, jj - 1) + func1(DP, ii - 1, jj - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int loop;
    cin >> loop;
    for (int z = 0; z < loop; z++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> DP(n, (vector<int>(m, 0)));

        for (int i = 0; i < m; i++)
        {
            DP[0][i] = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            DP[i][i] = 1;
        }
        // func1(DP, n - 1, m - 1);
        int ans = func1(DP, n - 1, m - 1);
        cout << ans << "\n";
    }
}