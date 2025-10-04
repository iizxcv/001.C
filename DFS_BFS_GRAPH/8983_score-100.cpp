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
        auto candidate_shoot_pos = lower_bound(hunters.begin(), hunters.end(), victim_x);
        bool shooting = false;

        if (candidate_shoot_pos != hunters.end())
        {
            int distance = abs(*candidate_shoot_pos - victim_x) + victim_y;
            if (distance <= c)
                shooting = true;
        }

        if (candidate_shoot_pos != hunters.begin())
        {
            // int distance = abs((*candidate_shoot_pos) - victim_x) + victim_y;
            auto left_shooter = prev(candidate_shoot_pos);
            int distance = abs(*left_shooter - victim_x) + victim_y;
            if (distance <= c)
                shooting = true;
        }
        if (shooting)
            cnt++;
    }
    cout << cnt;
}