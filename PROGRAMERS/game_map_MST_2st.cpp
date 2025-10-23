#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int ys = maps.size(), xs = maps[0].size();
    vector<vector<int>> dist(ys, vector<int>(xs, -1));
    queue<pair<int, int>> q;

    dist[0][0] = 1;
    q.push({0, 0});

    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();
        if (y == ys - 1 && x == xs - 1)
            return dist[y][x];

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < ys && nx >= 0 && nx < xs &&
                maps[ny][nx] == 1 && dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return -1; // 경로 없을 때
}