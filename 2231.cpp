#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

static int division_sum(int x)
{
    int result = 0;
    int val = 1;

    while (x > val)
    {
        int tmp_val = val;
        vector<int> tmp(0);
        int ten = 10;
        while (tmp_val / ten != 0)
        {
            tmp.push_back(tmp_val % ten);
            tmp_val /= ten;
        }
        tmp.push_back(tmp_val);

        if (accumulate(tmp.begin(), tmp.end(), 0) + val == x)
        {
            result = val;
            return result;
        }
        val++;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << division_sum(n) << "\n";

    return 0;
}