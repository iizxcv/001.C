#include <iostream>
#include <math.h>

using namespace std;

int func1(int recu_cnt, int vtx)
{
    int result = 0;
    int vsqrt = sqrt(vtx);
    result = vtx + ((vtx - (vsqrt)) * 2) + (vtx - ((vsqrt * 2) - 1));
    recu_cnt--;
    if (recu_cnt != 0)
    {
        result = func1(recu_cnt, result);
    }

    return result;
}

int main()
{
    int ans;
    int n;
    cin >> n;
    int vertex = 4;
    ans = func1(n, vertex);
    cout << ans;
    return 0;
}