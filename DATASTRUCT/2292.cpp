#include <iostream>

using namespace std;

int func1(int dst)
{

    int room = 1;
    int wall = 1;
    int angle = 6;

    while (wall < dst)
    {
        wall += angle;
        angle += 6;
        room++;
    }
    return room;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << func1(n);

    return 0;
}