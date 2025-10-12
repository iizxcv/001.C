#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> arr(5);
    vector<int> arr_size(5);
    int max_len = 0;
    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (auto c : s)
        {
            arr[i].push_back(c);
        }
        arr_size[i] = arr[i].size();
        max_len = max(max_len, arr_size[i]);
    }

    for (int i = 0; i < max_len; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr_size[j] > i)
            {
                cout << arr[j][i];
            }
        }
    }

    return 0;
}