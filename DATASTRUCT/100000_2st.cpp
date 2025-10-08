#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

template <typename T>
bool more_cmp(const T &a, const T &b)
{
    return a > b; //  a > b
}

template <>
bool more_cmp<tuple<int, int>>(const tuple<int, int> &a, const tuple<int, int> &b)
{
    const auto &[c1, d1] = a;
    const auto &[c2, d2] = b;
    if (d1 != d2)
        return d1 > d2;
    return c1 < c2;
    // if (get<1>(a) != get<1>(b))
    //     return get<1>(a) > get<1>(b);
    // return get<0>(a) < get<0>(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int result = 1;
    cin >> n;
    vector<tuple<int, int>> circles; // (위치, 타입: 1=열림, -1=닫힘)
    stack<tuple<int, int>> circles_s;

    for (int i = 0; i < n; i++)
    {
        int x, r;
        cin >> x >> r;
        circles.push_back({x - r, x + r}); // 원 시작거리, 끝거리
    }

    sort(circles.begin(), circles.end(), more_cmp<tuple<int, int>>);

    // const auto &[aa, bb] = circles[0];
    // circles_s.push({aa, bb});

    for (auto [S, D] : circles)
    {
        auto [PS, PD] = circles_s.top();
        if (PS == S && PD == D)
        {
            circles_s.pop();
            result++;
            result++;
            break;
        }
        if (!circles_s.empty())
        {
            auto [PS, PD] = circles_s.top();

            if (PS <= S && PD >= D)
            {
                circles_s.pop();
                PD = PD - abs(abs(S) - abs(D));
                circles_s.push({PS, PD});
            }
        }

        else
        {
            circles_s.pop();
            result++;
        }
        circles_s.push({S, D});
    }

    for (int i = 0; i < n; i++)
    {
        const auto &[a, b] = circles[i];
        cout << a << " " << b << endl;
    }
    cout << result;
    return 0;
}

// auto [a, b] = circles_s.top();
// cout << a << " " << b;