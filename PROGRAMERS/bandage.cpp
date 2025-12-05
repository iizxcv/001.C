#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::min/max를 사용하기 위해 포함 (solution 함수 내에서 사용 가능성 고려)

using namespace std;

// --- 제공해주신 solution 함수 ---
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int HP = health;
    int tick = 1;
    int timeStack = 1;
    vector<vector<int>>::iterator attack_iter = attacks.begin();
    
    while(0 < HP)
    {
        if(attack_iter == attacks.end()) break;
        if(HP <= 0) break;

        if (attack_iter != attacks.end() && tick == (*attack_iter)[0]){
            HP -= (*attack_iter)[1];
            timeStack =0;
            if(HP <= 0) break;
            attack_iter++;
        }
        else if(HP < health){
            HP += bandage[1];
            if (HP > health) HP = health;
            if((timeStack % bandage[0]) == 0)
            {
                timeStack = 0;
                HP += bandage[2];
                if (HP > health) HP = health;
            }
        }
    tick++;
    timeStack++;
    }

    if(HP <= 0) answer = -1;
    else answer = HP;

    return answer;
}
// ------------------------------------

// 테스트 케이스 실행 및 출력 함수
void run_test(const vector<int>& bandage, int health, const vector<vector<int>>& attacks, int expected, int test_num) {
    int result = solution(bandage, health, attacks);
    
    cout << "--- Test Case " << test_num << " ---" << endl;
    cout << "Bandage: [" << bandage[0] << ", " << bandage[1] << ", " << bandage[2] << "], Health: " << health << endl;
    cout << "Attacks: [";
    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << "[" << attacks[i][0] << ", " << attacks[i][1] << "]" << (i == attacks.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    cout << "Expected Result: " << expected << endl;
    cout << "Actual Result: " << result << endl;
    if (result == expected) {
        cout << "Status: PASS ✅" << endl;
    } else {
        cout << "Status: FAIL ❌" << endl;
    }
    cout << "----------------------" << endl;
}

int main() {
    // 1. [5, 1, 5], 30, [[2, 10], [9, 15], [10, 5], [11, 5]] -> 5
    run_test({5, 1, 5}, 30, {{2, 10}, {9, 15}, {10, 5}, {11, 5}}, 5, 1);

    // 2. [3, 2, 7], 20, [[1, 15], [5, 16], [8, 6]] -> -1
    run_test({3, 2, 7}, 20, {{1, 15}, {5, 16}, {8, 6}}, -1, 2);

    // 3. [4, 2, 7], 20, [[1, 15], [5, 16], [8, 6]] -> -1
    run_test({4, 2, 7}, 20, {{1, 15}, {5, 16}, {8, 6}}, -1, 3);
    
    // 4. [1, 1, 1], 5, [[1, 2], [3, 2]] -> 3
    run_test({1, 1, 1}, 5, {{1, 2}, {3, 2}}, 3, 4);

    // 추가 테스트: 마지막 공격에 체력이 0이 되는 경우
    run_test({10, 10, 10}, 10, {{1, 10}}, -1, 5);

    // 추가 테스트: 힐만 하는 경우 (공격 없음)
    run_test({1, 1, 1}, 5, {}, 5, 6);
    
    return 0;
}