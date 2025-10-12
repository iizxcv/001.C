#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    // int result;

    int n,
        b;

    cin >> n >> b;
    string result;
    while ((n / b) > 0)
    {

        char lot = (n % b) < 10 ? n % b + 48 : n % b + 55;
        n = n / b;

        result.push_back(lot);
    }
    char lott = (n) < 10 ? n + 48 : n % b + 55;
    result.push_back((lott));
    reverse(result.begin(), result.end());
    cout << result;
}