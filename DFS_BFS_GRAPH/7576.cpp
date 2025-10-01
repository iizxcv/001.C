#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

// -1 토마토가 들어있지 않음
// 0 토마토가 안익음
// 1 시작부터 익어 있는 토마토

// 상 하 좌 우
static const vector<tuple<int, int>> move_dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bake_tomato(vector<vector<int>> *pmap)
{
    int size_y = (*pmap).size();
    int size_x = (*pmap)[0].size();
    int tick = 0;
    int backcnt = 0;
    deque<tuple<int, int, int>> q;

    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            if ((*pmap)[i][j] == 1)
            {
                q.push_back({i, j, (*pmap)[i][j]});
                backcnt++;
            }
            if ((*pmap)[i][j] == -1)
            {
                backcnt++;
            }
        }
    }
    if (backcnt == (size_y * size_x))
    {
        return 0;
    }

    while (!q.empty())
    {
        tuple<int, int, int> tomato = q.front();
        q.pop_front();
        int ty, tx, tbake;
        ty = get<0>(tomato);
        tx = get<1>(tomato);
        tbake = get<2>(tomato);

        for (auto &mv : move_dir)
        {
            int my = get<0>(mv);
            int mx = get<1>(mv);

            int ny = my + ty;
            int nx = mx + tx;

            if (
                0 <= ny && ny < size_y &&
                0 <= nx && nx < size_x &&
                (*pmap)[ny][nx] == 0)
            {
                (*pmap)[ny][nx] = (*pmap)[ty][tx] + 1;
                q.push_back({ny, nx, (*pmap)[ny][nx]});
                tick = max(tick, (*pmap)[ny][nx]);
            }
        }
    }
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            // cout << (*pmap)[i][j] << " ";
            if ((*pmap)[i][j] == 0)
            {
                return -1;
            }
        }
        // cout << "\n";
    }
    return tick - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> m >> n;

    vector<vector<int>> wmap(n, (vector<int>(m, 0)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> wmap[i][j];
        }
    }
    cout << bake_tomato(&wmap);
}