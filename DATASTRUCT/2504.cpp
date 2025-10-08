#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> st;
    int result = 0;
    int temp = 1; // 현재 깊이의 곱셈 값

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == '(')
        {
            if (st.empty())
            {
                temp = 1;
            }
            temp *= 2;
            st.push(c);
        }
        else if (c == '[')
        {
            if (st.empty())
            {
                temp = 1;
            }
            temp *= 3;
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                result = 0;
                break;
            }

            // 바로 직전이 '('면 값 더하기
            if (s[i - 1] == '(')
            {
                result += temp;
            }

            st.pop();
            temp /= 2; // 깊이 감소
        }
        else if (c == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                result = 0;
                break;
            }

            // 바로 직전이 '['면 값 더하기
            if (s[i - 1] == '[')
            {
                result += temp;
            }
            st.pop();
            temp /= 3;
        }
    }
    if (s.length() > 30 || !st.empty())
    {
        cout << 0;
    }
    else
    {
        cout << result;
    }
}