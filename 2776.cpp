#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

static void compare_num(vector<int> a, vector<int> b)
{

    // a to b compare;
    sort(a.begin(), a.end());
    for (int target : b)
    {
        if (binary_search(a.begin(), a.end(), target))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int an;
        cin >> an;
        vector<int> arr_a(an);
        for (int i = 0; i < an; i++)
        {
            cin >> arr_a[i];
        }

        int bn;
        cin >> bn;
        vector<int> arr_b(bn);
        for (int i = 0; i < bn; i++)
        {
            cin >> arr_b[i];
        }

        compare_num(arr_a, arr_b);
    }
}