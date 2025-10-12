#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main()
{

    int avg = 0;
    int mid_val = 0;
    int low_acc = 4000;
    int range = 0;

    int n;
    cin >> n;
    vector<int> arr;
    unordered_map<int, int> arr_account;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());

    int sum = 0;
    int mid = n / 2;
    for (auto x : arr)
    {
        sum += x;
        arr_account[x]++;
    }
    mid_val = arr[mid];
    avg = floor((float(sum) / n) + 0.5);
    vector<pair<int, int>> v(arr_account.begin(), arr_account.end());
    sort(v.begin(), v.end(), [](const auto &a, const auto &b)
         {
        if (a.second != b.second)return a.second > b.second;
        return a.first < b.first; });

    low_acc = v.size() > 1 && v[0].second == v[1].second ? v[1].first : v[0].first;
    range = arr.back() - arr.front();

    cout << avg << "\n"
         << mid_val << "\n"
         << low_acc << "\n"
         << range;
}
