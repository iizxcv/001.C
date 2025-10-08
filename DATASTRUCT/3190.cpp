#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

tuple<int, int> turnRight(int dy, int dx)
{
    return {-dx, dy};
}
tuple<int, int> turnLeft(int dy, int dx)
{
    return {dx, -dy};
}

int main()
{
    tuple<int, int> direction = {1, 0};

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<tuple<int, int>> body;

    int n;
    cin >> n;
    vector<vector<int>> wmap(n, vector<int>(n, 0));
    int apples;
    cin >> apples;
    for (int i = 0; i < apples; i++)
    {
        int y, x;
        cin >> y >> x;
        wmap[x - 1][y - 1] = 'A';
    }
    int m;
    cin >> m;
    deque<tuple<int, char>> actions;
    for (int i = 0; i < m; i++)
    {
        int t;
        char act;
        cin >> t >> act;
        actions.push_back({t, act});
    }

    body.push_back({0, 0});

    int turn = 0;

    int acting_turn = 0;
    char next_act = 0;
    tie(acting_turn, next_act) = actions.front();
    actions.pop_front();
    while (1)
    {

        auto [dy, dx] = direction;
        auto [cy, cx] = body.front();

        wmap[cy][cx] = 1;

        cy += dy, cx += dx;
        body.push_front({cy, cx});

        ++turn;

        if (0 <= cx && cx < n && 0 <= cy && cy < n && wmap[cy][cx] != 1)
        {
            if (wmap[cy][cx] == 'A')
            {
            }
            else
            {
                auto [rm_y, rm_x] = body.back();
                body.pop_back();
                wmap[rm_y][rm_x] = 0;
            }
        }
        else
        {
            break;
        }
        if (acting_turn == turn)
        {
            if (next_act == 'D')
            {
                direction = turnRight(dy, dx);
                tie(dx, dy) = direction;
            }
            else if (next_act == 'L')
            {
                direction = turnLeft(dy, dx);
                tie(dx, dy) = direction;
            }
            if (!actions.empty())
            {
                tie(acting_turn, next_act) = actions.front();
                actions.pop_front();
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << wmap[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << turn;
    return 0;
}
