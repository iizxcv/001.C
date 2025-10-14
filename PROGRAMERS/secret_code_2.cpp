#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

// 비밀코드 10 <= n <= 30
// 1 <= (q의 길이 = m) < 10
// 1 ≤ q[i][j] ≤ n
// ans의 길이 = m

// for i,j 가 있다고 한다면,
// i와 i+1 의 ans는 min값 일꺼고, min
using namespace std;

int same_vectors(const std::vector<int> &a, const std::vector<int> &b)
{
    int i = 0, j = 0, cnt = 0;
    while (i < (int)a.size() && j < (int)b.size())
    {
        if (a[i] == b[j])
        {
            ++cnt;
            ++i;
            ++j;
        }
        else if (a[i] < b[j])
            ++i;
        else
            ++j;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> q, vector<int> ans)
{
    // q[i] , ans
    int q_size = q.size();
    int answer = 0;
    vector<int> S(5);
    for (auto &row : q)
        sort(row.begin(), row.end());

    for (int i1 = 1; i1 <= n - 4; i1++)
    {
        S[0] = i1;
        for (int i2 = i1 + 1; i2 <= n - 3; i2++)
        {
            S[1] = i2;
            for (int i3 = i2 + 1; i3 <= n - 2; i3++)
            {
                S[2] = i3;
                for (int i4 = i3 + 1; i4 <= n - 1; i4++)
                {
                    S[3] = i4;
                    for (int i5 = i4 + 1; i5 <= n; i5++)
                    {
                        S[4] = i5;
                        int check = 0;
                        for (int i = 0; i < q.size(); i++)
                        {
                            if (same_vectors(S, q[i]) == ans[i])
                                check++;
                        }
                        if (check == q_size)
                        {
                            answer++;
                        }
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // int n = 10;
    int n = 15;
    // vector<vector<int>> q = {{1, 2, 3, 4, 5},
    //                          {6, 7, 8, 9, 10},
    //                          {3, 7, 8, 9, 10},
    //                          {2, 5, 7, 9, 10},
    //                          {3, 4, 5, 6, 7}};
    vector<vector<int>> q = {{2, 3, 9, 12, 13},
                             {1, 4, 6, 7, 9},
                             {1, 2, 8, 10, 12},
                             {6, 7, 11, 13, 15},
                             {1, 4, 10, 11, 14}};

    vector<int>
        // ans = {2, 3, 4, 3, 3};
        ans = {2, 1, 3, 0, 1};

    cout << solution(n, q, ans);
    return 0;
}
