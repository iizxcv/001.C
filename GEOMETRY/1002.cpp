#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int result;
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    float sub = r1 > r2 ? r1 - r2 : r2 - r1;
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (dist == 0 && r1 == r2)
        result - 1;
    else if (dist < r1 + r2 && (sub < dist))
        result = 2;
    else if (dist == r1 + r2 || dist == sub)
        result = 1;

    cout << dist;

    return 0;
}
