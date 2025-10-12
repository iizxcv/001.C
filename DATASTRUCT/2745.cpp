#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int system;
    int result = 0;
    cin >> s >> system;
    int pow = 1;
    int sft = s.size();
    for (int i = sft - 1; i >= 0; i--)
    {
        int num;
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            num = s[i] - (int('A') - 10);
        }
        else
        {
            num = s[i] - 48;
        }
        result += pow * num;
        pow *= system;
    }

    // cout << int('4') - (int('A') - 10);
    // cout << int('0');
    cout << result;

    return 0;
}