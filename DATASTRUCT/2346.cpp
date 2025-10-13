#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    deque<pair<int, int>> arr;

    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back({i, tmp});
    }

    vector<int> order;
    order.reserve(n);

    while (!arr.empty())
    {
        auto [idx, k] = arr.front();
        arr.pop_front();
        order.push_back(idx);

        if (arr.empty())
            break;

        if (k > 0)
        {
            int rotate = (k - 1) % (int)arr.size();
            while (rotate--)
            {
                arr.push_back(arr.front());
                arr.pop_front();
            }
        }
        else if (k < 0)
        {
            int rotate = (-k) % (int)arr.size();
            while (rotate--)
            {
                arr.push_front(arr.back());
                arr.pop_back();
            }
        }
    }
    for (auto ans : order)
    {
        cout << ans << " ";
    }

    return 0;
}