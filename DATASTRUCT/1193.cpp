#include <iostream>
using namespace std;

void AmBp(int &a, int &b)
{
    a--;
    b++;
}

void func1(int dst)
{
    int cnt = 1;
    int i = 1, j = 1;
    int *tp_i = &i;
    int *tp_j = &j;
    int max_v = 1;
    bool turn = false;
    while (dst > cnt)
    {
        if (turn)
        {
            swap(tp_i, tp_j);
            turn = false;
        }
        cnt++;
        if ((*tp_i) > 1)
            (*tp_i)--;

        (*tp_j)++;
        if (max_v < *tp_i || max_v < *tp_j)
        {
            turn = true;
            max_v = max(i, j);
        }
    }
    cout << i << "/" << j << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    func1(n);
}