#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

static bool can_pack(const vector<int> &a, long long X, int M)
{
    long long cur = 0;
    int used = 1; // 최소 1장부터 시작
    for (int len : a)
    {
        if (cur + len > X) // X 보다
        {                  // 새 블루레이 필요
            ++used;
            cur = 0;
        }
        cur += len;
    }
    return used <= M;
}

int main()
{
    // 코테 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M))
        return 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    long long lo = *max_element(a.begin(), a.end());    // 한 장 최소 크기 하한
    long long hi = accumulate(a.begin(), a.end(), 0LL); // 한 장 최대 크기 상한
    long long ans = hi;

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (can_pack(a, mid, M))
        { // mid로 M장 이내 가능
            ans = mid;
            hi = mid - 1; // 더 줄여본다
        }
        else
        {
            lo = mid + 1; // 늘린다
        }
    }
    cout << ans << "\n";
    return 0;
}
