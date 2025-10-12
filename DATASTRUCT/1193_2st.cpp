#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int line = 1;

    while (n > line)
    {
        n -= line;
        line++;
    }
    int a, b;
    if (line % 2 == 0)
    {
        a = n;
        b = line - n + 1;
    }
    else
    {
        a = line - n + 1;
        b = n;
    }

    cout << a << "/" << b;
    return 0;
}