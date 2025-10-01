#include <iostream>
#include <vector>

using namespace std;

static int DP[41];
static int cnt = 0;
int fibonacci(int n)
{
    if (n == 1 && n == 2)
        return 1;
    for (int i = 3; i <= n; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
        cnt++;
    }
    return DP[n];
}

int main()
{
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 1;

    int n;
    cin >> n;
    cout << fibonacci(n) << " " << cnt;

    return 0;
}