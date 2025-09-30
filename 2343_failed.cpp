#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
/*


*/

static bool blueray_count(vector<int> arr, int condition, int m)
{
    int cd = 1;
    int cur = 0;

    for (int len : arr)
    {
        if (cur + len > condition)
        {
            cd++;
            cur = 0;
        }
        cur += len;
    }
    return cd <= m;
}

int main()
{

    // std::cout << "aaa";

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (blueray_count(arr, mid, m))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << result << "\n";

    return 0;
}

// 0 1 3 6 10 15 | 21 28 | 36 45