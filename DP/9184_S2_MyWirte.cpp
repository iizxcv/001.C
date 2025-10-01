/*
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
*/

/*
런타임 에러... (OutOfBounds) 안전하지 않게 인덱스 범위를 초과해서 그렇다고 한다.
그래서 보간 작업도 해뒀는데.. ㅠ
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>
using namespace std;

static int DP[21][21][21];

int w(int a, int b, int c)
{
    // cout << a << " " << b << " " << c << "\n";
    if (a <= 0 || b <= 0 || c <= 0)
    {
        // cout << "*\n";
        return 1;
    }

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (a < b && b < c)
        return DP[a][b][c] =
                   (DP[a][b][c - 1] ? DP[a][b][c - 1] : (DP[a][b][c - 1] = w(a, b, c - 1))) +
                   (DP[a][b - 1][c - 1] ? DP[a][b - 1][c - 1] : (DP[a][b - 1][c - 1] = w(a, b - 1, c - 1))) -
                   (DP[a][b - 1][c] ? DP[a][b - 1][c] : (DP[a][b - 1][c] = w(a, b - 1, c)));

    return DP[a][b][c] =
               (DP[a - 1][b][c] ? DP[a - 1][b][c] : (DP[a - 1][b][c] = w(a - 1, b, c))) +
               (DP[a - 1][b - 1][c] ? DP[a - 1][b - 1][c] : (DP[a - 1][b - 1][c] = w(a - 1, b - 1, c))) +
               (DP[a - 1][b][c - 1] ? DP[a - 1][b][c - 1] : (DP[a - 1][b][c - 1] = w(a - 1, b, c - 1))) -
               (DP[a - 1][b - 1][c - 1] ? DP[a - 1][b - 1][c - 1] : (DP[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1)));
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    DP[0][0][0] = 1;

    // cout << w(2, 2, 2);

    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = "
             << w(a, b, c) << "\n";
    }
}