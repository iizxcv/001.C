#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

/*
메모리 초과가 뜸
shooting_range를 줄여서 메모리를 확보 해야 할 듯.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> hunters(a, 0);
    for (int i = 0; i < a; i++)
    {
        cin >> hunters[i];
    }
    sort(hunters.begin(), hunters.end());
    vector<tuple<int, int>> animals;
    for (int i = 0; i < b; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        animals.push_back({x, y});
    }

    // 입력 끝
    int max_x = 0;
    for (auto [tmp_x, tmp_y] : animals)
    {
        max_x = max(max_x, tmp_x);
    }

    // 동물을 순회해서 사격범위에 있으면 cnt++;
    // 이분탐색으로 사대 위치 nlogn으로 찾은 다음 |xi-aj| + bj 계산식 활용
    for (auto [victim_x, victim_y] : animals)
    {
        // 이분 탐색으로 가장 가까운 사대 찾기
        int l = 0, r = hunters.size() - 1;
        int min_dist = 1e9; // 충분히 큰 값

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int dist = abs(hunters[mid] - victim_x) + victim_y;
            if (dist < min_dist)
                min_dist = dist;

            if (hunters[mid] < victim_x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        if (min_dist <= c)
            cnt++;
    }
    cout << cnt;
}