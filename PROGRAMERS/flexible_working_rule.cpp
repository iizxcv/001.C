#include <string>
#include <vector>

using namespace std;

int itotime(int a)
{
    return (a / 100) * 60 + (a % 100);
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday)
{
    // 스케쥴은 출근 희망 시각 1차원 정수
    // timelogs 직원들이 일주일동한 출근한 시각을 담은 2차원
    // startday 이벤트를 시작한 요일을 의미하는 정수

    //     int answer = 0;
    //     return answer;
    int ans = 0;
    int day = startday - 1;
    vector<pair<int, int>> schedules_1;
    schedules_1.reserve(schedules.size());
    for (int i = 0; i < schedules.size(); i++)
    {
        int sche = itotime(schedules[i] + 10);
        int emp_size = timelogs[i].size();
        int cnt = 0;
        for (int j = 0; j < emp_size; j++)
        {
            int w = (startday + j - 1) % 7 + 1;
            if (w != 6 && w != 7)
            {
                int tlog = itotime(timelogs[i][j]);
                if (sche >= tlog)
                {
                    cnt++;
                }
                else
                    break;
            }
        }
        ans = cnt == 5 ? ans + 1 : ans;
    }

    return ans;
}