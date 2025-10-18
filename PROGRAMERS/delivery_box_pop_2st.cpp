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

    int h = (num - 1) / w;
    int pos = (num - 1) % w;
    int top_h = (n - 1) / w;

    // 세로선 통일 좌표계(짝수층 기준)
    int base = (h % 2 == 0) ? pos : (w - 1 - pos);

    // 위의 완전층 수(마지막 층 제외)
    int full_above = max(0, top_h - h - 1);

    // 마지막 층 유효 칸 수
    int last_cols = n - top_h * w;
    if (last_cols == 0)
        last_cols = w;

    // 마지막 층 존재 판정
    int exists_top = 0;
    if (top_h > h)
    {
        if (top_h % 2 == 0)
        {
            // L -> R: 유효 열 [0, last_cols-1]
            if (base < last_cols)
                exists_top = 1;
        }
        else
        {
            // R -> L: 유효 열 [w - last_cols, w-1]
            if (base >= w - last_cols)
                exists_top = 1;
        }
    }

    return 1 + full_above + exists_top;
}