#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

/*
사대의 위치 xi와 동물의 위치 (aj, bj) 간의 거리는 |xi-aj| + bj로 계산

for 사대
for y_distance > 0 클때까지, (i)
x_range = y_distance - i
for j = 사대 - x_range ; 사대 < x_rage * 2; j++;
if(0 < j < j + (x_range  *2 )) // x좌표 범위 계산
pos[i][j] 가 1이면 누적 +1

입력: 사대수, 동물의 수, 사정거리
입력2: 사대 위치 (y:0)
입력3s : 동물 위치
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> hunters(a, 0);
    sort(hunters.begin(), hunters.end());
    for (int i = 0; i < a; i++)
    {
        cin >> hunters[i];
    }
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

    vector<int> shooting_range(max_x + c, 0);
    for (int i = 0; i < max_x + 1; i++)
    {
        for (int j = 0; j < hunters.size(); j++)
        {
            int h_pos = abs(i - hunters[j]);
            shooting_range[i] = max(shooting_range[i], c - h_pos);
        }
    }
    // 동물을 순회해서 사격범위에 있으면 cnt++;
    for (auto [victim_x, victim_y] : animals)
    {
        if (victim_y <= shooting_range[victim_x])
        {
            cnt++;
        }
    }
    cout << cnt;
}