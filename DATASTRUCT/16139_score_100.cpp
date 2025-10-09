#include <iostream>
#include <map>
#include <tuple>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LowerBound(vector<tuple<int, int>> &vec, int target)
{
    int left = 0, right = vec.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (target > get<0>(vec[mid]))
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

int UpperBound(vector<tuple<int, int>> &vec, int target)
{
    int left = 0, right = vec.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (get<0>(vec[mid]) <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char, vector<tuple<int, int>>> alpha;
    map<char, int> alpha_sum;

    string s;
    cin >> s;

    int i = 0;
    for (auto c : s)
    {
        if (alpha[c].empty())
        {
            // alpha[c].push_back({-1, 0});
            alpha[c].push_back({i, 1});
        }
        else
        {
            const auto [ii, tmp_sum] = alpha[c].back();
            alpha[c].push_back({i, tmp_sum + 1});
        }
        i++;
    }
    int n;
    cin >> n;
    // deque<tuple<char, int, int>> questions;
    deque<int> ans;
    for (i = 0; i < n; i++)
    {
        char a;
        int b;
        int c;
        cin >> a >> b >> c;
        // questions.push_back({a, b, c});
        auto &vec = alpha[a];

        int src = LowerBound(vec, b);
        int dst = UpperBound(vec, c);

        if (src >= vec.size() || src >= dst)
        {
            cout << 0 << "\n";
        }
        else
        {
            dst--;
            int src_val = (src == 0) ? 0 : get<1>(vec[src - 1]);
            int dst_val = get<1>(vec[dst]);

            cout << dst_val - src_val << "\n";
            // cout << src << " " << dst << "\n";
        }
    }
    // for (auto answer : ans)
    // {
    //     cout << answer << "\n";
    // }
    //     cout << int('A') << '\n';
    //     cout << int('a') << '\n';
}
