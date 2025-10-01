#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
using namespace std;

static const vector<tuple<int, int>> move_dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool safety_zone_check(vector<vector<int>> &wmap, vector<vector<int>> &visited, int n, int y, int x)
{
    int map_size = wmap.size();
    deque<tuple<int, int>> q;
    q.push_front({y, x});

    if (wmap[y][x] > n)
    {
        visited[y][x] = 1;
    }

    while (!q.empty())
    {
        tuple<int, int> cv = q.front();
        int cy = get<0>(cv);
        int cx = get<1>(cv);
        q.pop_front();
        for (auto &mv : move_dir)
        {
            int my = get<0>(mv);
            int mx = get<1>(mv);
            int ny = cy + my, nx = cx + mx;

            if (0 <= ny && ny < map_size &&
                0 <= nx && nx < map_size &&
                wmap[ny][nx] > n &&
                visited[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                q.push_back({ny, nx});
            }
        }
    }
    return true;
}

int safety_bfs_cnt(vector<vector<int>> &wmap, int n)
{
    int map_size = wmap.size();
    vector<vector<int>> visited(map_size, vector<int>(map_size, 0));
    int cnt = 0;
    for (int i = 0; i < map_size; i++)
    {
        for (int j = 0; j < map_size; j++)
        {
            if (wmap[i][j] > n &&
                visited[i][j] == 0)
            {
                cnt = safety_zone_check(wmap, visited, n, i, j) ? cnt + 1 : cnt;
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int result = 0;
    int n;
    cin >> n;
    vector<vector<int>> pmap(n, vector<int>(n, 0));

    int max_val = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> pmap[i][j];
            max_val = max(max_val, pmap[i][j]);
        }
    }
    for (int i = 0; i <= max_val; i++)
    {
        result = max(result, safety_bfs_cnt(pmap, i));
    }
    cout << result;
}