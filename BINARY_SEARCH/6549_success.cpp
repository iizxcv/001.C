#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

long long func_1(vector<long long> &hist)
{
    stack<int> s;
    long long maxArea = 0;
    int n = hist.size();

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && hist[s.top()] > hist[i])
        {
            int h = hist[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, (long long)h * width);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int h = hist[s.top()];
        s.pop();
        int width = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, (long long)h * width);
    }

    return maxArea;
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
