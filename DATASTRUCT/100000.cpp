#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<pair<int, int>> stack;
    vector<pair<int, int>> stack2;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p; // point;
        int r; // radius;
        cin >> p >> r;

        int s = p - r; // start
        int d = p + r; // destination

        stack.push_back({s, d});
    }

    sort(stack.begin(), stack.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });

    // while (!stack.empty())
    // {
    //     auto [cur_s, cur_d] = stack.back();
    //     cout << cur_s << " " << cur_d << "\n";
    //     stack.pop_back();
    // }
    int base_s, base_d;
    auto [base_s, base_d] = stack.back();
    stack.pop_back();
    int remain_range = 0;
    int result = 1;
    while (!stack.empty())
    {
        auto [cur_s, cur_d] = stack.back();
        stack.pop_back();
        result++;
        if ((base_d == cur_d))
        {
            stack2.push_back({base_s, base_d});
            base_s = cur_s, base_d = cur_d;
            continue;
        }
        while (!stack2.empty() && base_d >= cur_d)
        {
            int tmp_s = base_s, tmp_d = base_d;
            auto [base_s, base_d] = stack2.back();
            stack.pop_back();
            remain_range -= tmp_d - tmp_s;
        }
    }
}