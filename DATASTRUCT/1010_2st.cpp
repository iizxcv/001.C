#include <iostream>
using namespace std;
int main()
{
    int t;
    unsigned long long int a, b, i, n = 1;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        cin >> a >> b;
        if (a * 2 < b)
        {
            for (i = b; i > b - a; i--)
            {
                n *= i;
            }
            for (i = a; i >= 1; i--)
            {
                n /= i;
            }
            cout << n << "\n";
            n = 1;
        }
        else
        {
            for (i = b; i > a; i--)
            {
                n *= i;
            }
            for (i = b - a; i >= 1; i--)
            {
                n /= i;
            }
            cout << n << "\n";
            n = 1;
        }
    }
    return 0;
}