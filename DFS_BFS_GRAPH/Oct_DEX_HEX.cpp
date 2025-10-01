#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

    string in_data;
    cin >> in_data;

    int result = 0;

    if (in_data[0] == '0')
    {
        if (in_data[1] == 'x')
        {
            string sub = in_data.substr(2);
            int dec_val = std::stoi(sub, nullptr, 16);
            result = dec_val;
        }
        else
        {
            string sub = in_data.substr(1);
            int dec_val = std::stoi(sub, nullptr, 8);
            result = dec_val;
        }
    }
    else
    {
        result = stoi(in_data);
    }

    cout << result;

    return 0;

}