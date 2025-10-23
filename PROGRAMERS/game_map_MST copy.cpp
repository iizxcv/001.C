#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

// pair<int, int> turnRight(pair<int,int> pos){
//     int temp = pos.first;
//     pos.first = pos.second *(-1);
//     pos.second = temp;

//     return pos;
// }

// class Player{
// private:
//     int team;
//     pair<int, int> pos;         //위치
//     pair<int, int> dir;         //방향
//     vector<vector<int>> *visit;
//     int move_cnt = 1;

// public:
//     Player(int t, int start_pos, int start_dir, visit_map);
//     ~Player(){ delete[] visit}
//     void p_turnRight();

// }

// void p_turnRight(){
//     int temp = pos.first;
//     pos.first = pos.second *(-1);
//     pos.second = temp;
// }

// void p_move(&vector<vector<int>> map){
//     if(visit[pos.first + pos.second][])
// }

tuple<int, int> p_turnRight(tuple<int, int> pos)
{
    int temp = get<0>(pos);
    get<0>(pos) = get<1>(pos) * (-1);
    get<1>(pos) = temp;

    return pos;
}

int solution(vector<vector<int>> maps)
{

    int answer = 1e9;

    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    int xs = maps[0].size();
    int ys = maps.size();
    tuple<int, int> dst_pos = {maps.size(), maps[0].size()};
    tuple<int, int> dir = {1, 0};

    vector<tuple<int, int, int>> stk;

    stk.push_back({0, 0, 1});

    while (!stk.empty())
    {

        auto [y, x, cnt] = stk.front();
        stk.pop_back();
        visited[y][x] = 1;

        for (int i = 0; i < 4; i++)
        {
            dir = p_turnRight(dir);
            auto [my, mx] = dir;
            int ny = y + my;
            int nx = x + mx;

            if (0 <= ny && ny < ys &&
                0 <= nx && nx < xs &&
                maps[ny][nx] == 1 && !visited[ny][nx])
            {
                if (ny == ys - 1 && nx == xs - 1)
                {
                    answer = min(cnt + 1, answer);
                    break;
                }
                stk.push_back({ny, nx, cnt + 1});
            }
        }
    }

    return answer;
}

int main()
{

    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};

    std::cout << solution(maps);

    return 0;
}