#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <deque>
#include <tuple>
using namespace std;

// 상 우 하 좌
static const vector<pair<int, int>> move_dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int min_path(vector<vector<int>> *fmap, vector<vector<int>> *visited, int sy, int sx, int dy, int dx)
{
    int map_size_y = (*fmap).size();
    int map_size_x = (*fmap)[0].size();
    (*visited)[sy][sx] = 1;
    int move_count = 0;
    deque<tuple<int, int, int>> dq;
    dq.push_back({sy, sx, move_count + 1});
    while (!dq.empty())
    {
        auto [sy, sx, move_count] = dq.front();
        dq.pop_front();

        if (sy == dy && sx == dx)
        {
            return move_count;
        }

        if (sy == dy && sx == dx)
            return move_count;

        for (auto [my, mx] : move_dir)
        {
            int ny = sy + my, nx = sx + mx;
            if (0 < ny && ny < map_size_y && 0 < nx && nx < map_size_x && (*fmap)[ny][nx] == 1 && (*visited)[ny][nx] != 1)
            {
                (*visited)[ny][nx] = 1;
                dq.push_back({ny, nx, move_count + 1});
            }
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> wmap(n + 1, (vector<int>(m + 1, 0)));

    for (int i = 1; i < n + 1; i++)
    {
        char col[m];
        cin >> col;
        for (int j = 1; j < m + 1; j++)
        {
            wmap[i][j] = int(col[j - 1]) - '0';
        }
    }
    // for (int i = 1; i < n + 1; i++)
    // {
    //     for (int j = 1; j < m + 1; j++)
    //     {
    //         cout << wmap[i][j];
    //     }
    //     cout << "\n";
    // }
    vector<vector<int>> visited(wmap.size(), (vector<int>(wmap[0].size(), 0)));
    cout << min_path(&wmap, &visited, 1, 1, n, m);

    return 0;
}