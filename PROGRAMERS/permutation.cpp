#include <bits/stdc++.h>
using namespace std;

template <class F>
void for_each_comb_10_choose_5(F &&f)
{
    vector<int> mask(10, 0);
    fill(mask.end() - 5, mask.end(), 1);
    do
    {
        array<int, 5> pick;
        int k = 0;
        for (int i = 0; i < 10; ++i)
            if (mask[i])
                pick[k++] = i + 1;
        f(pick);
    } while (next_permutation(mask.begin(), mask.end()));
}

int main()
{
    size_t cnt = 0;
    for_each_comb_10_choose_5([&](const array<int, 5> &a)
                              {
        // 여기서 바로 사용/출력/처리
        // 예) 앞 몇 개만 출력
        // if (cnt < 5) {
            for (int x : a) cout << x << ' ';
            cout << '\n';
        // }
        ++cnt; });
    cout << "count = " << cnt << '\n';
}