#include <deque>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

static const vector<tuple<int, int>> move_dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

static int coloring_apt(vector<vector<int>> *map, vector<vector<int>> *visited, int sy, int sx)
{

    int map_size = (*map).size();
    deque<tuple<int, int>> q;
    int cnt = 1;
    q.push_back({sy, sx});
    (*visited)[sy][sx] = 1;
    while (!q.empty())
    {
        tuple<int, int> cur = q.front();
        q.pop_front();
        int y = get<0>(cur), x = get<1>(cur);

        for (auto mv : move_dir)
        {
            int mv_y = get<0>(mv), mv_x = get<1>(mv);
            int ny = y + mv_y, nx = x + mv_x;
            if (0 < ny && ny < map_size && 0 < nx && nx < map_size && (*visited)[ny][nx] == 0 && (*map)[ny][nx] == 1)
            {
                q.push_back({ny, nx});
                (*visited)[ny][nx] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

static void count_apt(vector<vector<int>> *map, vector<vector<int>> *visited)
{
    vector<int> output;
    for (int i = 1; i < (*map).size(); i++)
    {
        for (int j = 1; j < (*map).size(); j++)
        {
            if ((*visited)[i][j] == 0 && (*map)[i][j] == 1)
            {
                output.push_back(coloring_apt(map, visited, i, j));
            }
        }
    }
    if (output.empty())
    {
        cout << 0 << "\n";
    }
    else
    {
        sort(output.begin(), output.end());
        cout << output.size() << "\n";
        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i] << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        string m;
        cin >> m;
        for (int j = 1; j < n + 1; j++)
        {
            map[i][j] = int(m[j - 1]) - 48;
        }
    }

    // for (int i = 1; i < n + 1; i++)
    // {
    //     for (int j = 1; j < n + 1; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    count_apt(&map, &visited);
}

/*

7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
*/