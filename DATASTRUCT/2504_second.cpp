#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> st;
    stack<char> mux;
    int result = 0;
    int ALU = 0;
    int temp = 1; // 현재 깊이의 곱셈 값

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    char prev = 0;
    while (!st.empty())
    {
        char a = st.top();
        st.pop();

        if (a == ')' || a == ']')
        {
            if ((prev == '(' || prev == '[') && temp != 1)
            {
                ALU += temp;
                temp = 1;
            }

            mux.push(a);
            prev = a;
            // continue;
        }
        if (!mux.empty())
        {
            if (a == '(' && mux.top() == ')')
            {
                mux.pop();
                temp *= 2;
                prev = a;
            }
            else if (a == '[' && mux.top() == ']')
            {
                mux.pop();
                temp *= 3;
                prev = a;
            }
        }
        if (mux.empty())
        {
            if (a == '(' || a == '[')
            {
                if (ALU != 0)
                {
                    result += (ALU * sqrt(temp)) + temp;
                }
                else
                {
                    result += temp;
                }
            }
            temp = 1;
            // ALU = 0;
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
