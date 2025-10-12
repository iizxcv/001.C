#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        int m, find_doc;
        cin >> m >> find_doc;
        deque<pair<int, bool>> docs;
        int count1 = 0;
        for (int j = 0; j < m; j++)
        {
            int doc;
            cin >> doc;
            if (count1 == find_doc)
            {
                docs.push_back({doc, true});
            }
            else
            {
                docs.push_back({doc, false});
            }

            count1++;
        }
        int cnt = 0;

        while (!docs.empty())
        {
            auto [a, b] = docs.front();

            auto it = max_element(docs.begin(), docs.end());
            int max_val;
            if (it != docs.end())
                max_val = get<0>(*it);
            it = docs.begin();

            if (max_val != a)
            {
                docs.pop_front();
                docs.push_back({a, b});
                continue;
            }
            else
            {
                docs.pop_front();
                ++cnt;
            }
            if (b)
            {
                break;
            }
        }
        ans[i] = cnt;
    }
    for (auto answer : ans)
    {
        cout << answer << "\n";
    }

    return 0;
}
