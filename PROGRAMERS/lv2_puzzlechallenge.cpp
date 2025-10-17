#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit)
{

    int left = 1;
    int right = 0;
    auto max_tmp = max_element(diffs.begin(), diffs.end(), [](const int &a, const int &b)
                               { return a < b; });
    if (max_tmp != diffs.end())
    {
        right = *max_tmp;
    }
    int n = diffs.size();

    while (left < right)
    {
        int mid = (left + right) / 2;
        long long lv_tot = 0;

        for (int i = 0; i < n; i++)
        {
            int cost = 0;
            long long prepro_val = diffs[i] - mid;
            if (i == 0)
            {
                cost = times[0];
            }
            else
            {
                cost = prepro_val > 0 ? (times[i] + times[i - 1]) * prepro_val + times[i] : times[i];
            }
            lv_tot += cost;

            if (limit < lv_tot)
            {
                break;
            }
        }

        if (lv_tot <= limit)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    int answer = left;
    return answer;
}

int main()
{
    vector<int> diffs = {1, 328, 467, 209, 54};
    vector<int> times = {2, 7, 1, 4, 3};
    long long limit = 1723;

    cout << solution(diffs, times, limit);

    return 0;
}