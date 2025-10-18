#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num)
{
    // 일단 num의 h(몫)과 인덱스를 구해
    // 서로 같으면 n-num /w 하면 됌
    // 다르면
    // 위에 박스가 있는지 유무는 나눈값이 짝수면 정방향
    // 홀수면 역방향으로 계산해야 되므로, (n/w) /2 -> (n/w +1) + ((w-(num%w))+1)
    int answer = 0;

    int num_h = (num - 1) / w;
    int n_h = (n - 1) / w;

    if ((n_h % 2) == (num_h % 2))
    {

        answer = ((n - num) / w);
    }
    else
    {
        answer = n_h - num_h;
        answer += ((n % w) + (num % w)) / (w + 1);
        //     int top_box = (n_h*w) + ((w-(num%w))+1);
        //     if(top_box < n){
        //         answer = ((n-num) /w);
        //     }
        //     else{answer = ((n-num) /w) +1;}
    }

    // vector<vector<int>> room;
    // int h = (n / w) + 1;
    // int box_cnt = 1;
    // int direction = -1;
    //     for(int i = 0; i < h; i++){
    //         room.push_back(vector<int>(w,0));

    //         if(direction > 0){
    //         for(int j = 0; j < w; j < j++){
    //             room[i][j] = box_cnt++;
    //         }}
    //         else if(direction < 0){
    //         for(int j = w-1; j >= 0; j < j--){
    //             room[i][j] = box_cnt++;
    //         }}
    //         direction*=-1;
    //     }

    return answer + 1;
}