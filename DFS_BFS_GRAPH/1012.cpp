#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

static const vector<tuple<int, int>> move_dir = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

bool diffusion_earthworm(vector<vector<int>> *map, vector<vector<int>> *visited2, int cx, int cy)
{
    int map_size_x = (*map)[0].size();
    int map_size_y = (*map).size();

    int result = 0;
    deque<tuple<int, int>> q;
    q.push_back({cx, cy});
    (*visited2)[cy][cx] = 1;
    while (!q.empty())
    {
        tuple<int, int> cur = q.front();
        int x = get<0>(cur), y = get<1>(cur);
        q.pop_front();
        result++;

        for (auto &mv : move_dir)
        {
            int mx = get<0>(mv), my = get<1>(mv);

            int nx = mx + x, ny = my + y;
            if (0 <= nx && nx < map_size_x &&
                0 <= ny && ny < map_size_y &&
                (*visited2)[ny][nx] == 0 &&
                (*map)[ny][nx] == 1)
            {
                q.push_back({nx, ny});
                (*visited2)[ny][nx] = 1;
            }
        }
    }
    return result > 0 ? true : false;
}

int expection_worm_count(vector<vector<int>> *map, vector<vector<int>> *visited1)
{
    int cnt = 0;
    int map_size_x = (*map)[0].size();
    int map_size_y = (*map).size();
    for (int x = 0; x < map_size_x; x++)
    {
        for (int y = 0; y < map_size_y; y++)
        {
            if ((*visited1)[y][x] == 0 &&
                (*map)[y][x] == 1)
            {
                if (diffusion_earthworm(map, visited1, x, y))
                    cnt++;
            }
        }
    }
    return cnt;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> n_count(n, 0);

    for (int i = 0; i < n; i++)
    {

        int map_x, map_y, v;
        cin >> map_x >> map_y >> v;

        vector<vector<int>> wmap(map_y, vector<int>(map_x, 0));
        vector<vector<int>> visited(map_y, vector<int>(map_x, 0));

        for (int ii = 0; ii < v; ii++)
        {
            int cabbage_x, cabbage_y;
            cin >> cabbage_x >> cabbage_y;
            wmap[cabbage_y][cabbage_x] = 1;
        }

        n_count[i] = expection_worm_count(&wmap, &visited);

        // for (int j = 0; j < map_y; j++)
        // {
        //     for (int k = 0; k < map_x; k++)
        //     {
        //         cout << visited[j][k];
        //     }
        //     cout << "\n";
        // }
    }
    for (auto &co : n_count)
    {
        cout << co << "\n";
    }

    return 0;
}