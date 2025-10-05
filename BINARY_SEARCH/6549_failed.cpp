#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX
#include <tuple>

using namespace std;

long long calc_box_max_size(vector<long long> &histo, long long start, long long end)
{
    long long max_val = 0;
    long long min_box = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        min_box = min(min_box, histo[i]);
    }
    min_box *= (end - start) + 1;
    max_val = max(histo[start], histo[end]);
    max_val = max(max_val, min_box);

    return max_val;
}

long long func_1(vector<long long> &histo)
{

    long long n = histo.size();
    long long result = 0;
    vector<tuple<long long, long long>> stack;
    stack.push_back({0, n - 1});

    while (!stack.empty())
    {
        auto [str, end] = stack.back();
        stack.pop_back();
        result = max(result, calc_box_max_size(histo, str, end));
        long long mid = (str + end) / 2;

        if (0 <= str && str < mid && mid < end && end < n && str < end)
        {
            stack.push_back({mid, end});
            stack.push_back({str, mid - 1});

            long long mid_minus = mid - 1;
            long long mid_plus = mid + 1;
            long long old_mid_left_max = 0;
            long long mid_left_max = 0;
            long long old_mid_right_max = 0;
            long long mid_right_max = 0;

            while (mid_minus >= str && old_mid_left_max < (mid_left_max = calc_box_max_size(histo, mid_minus, mid)))
            {
                old_mid_left_max = mid_left_max;
                --mid_minus;
            }
            while (mid_minus <= end && old_mid_right_max < (mid_right_max = calc_box_max_size(histo, mid, mid_plus)))
            {
                old_mid_right_max = mid_right_max;
                ++mid_plus;
            }
            long long mid_tmp = max(mid_left_max, mid_right_max);
            result = max(result, mid_tmp);
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> ans;

    while (1)
    {
        int n;
        cin >> n;
        if (n <= 0)
            break;

        vector<long long> hist;
        for (int i = 0; i < n; i++)
        {
            long long a;
            cin >> a;
            hist.push_back(a);
        }
        ans.push_back(func_1(hist));
    }

    for (auto a : ans)
    {
        cout << a << "\n";
    }
}
