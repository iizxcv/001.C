#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
// 0-25 // a == 97 //

int __ctoi(char c)
{
    return int(c - 96);
}
char __itoc(int i)
{
    return char((i + 96));
}

long long __stoi(string s)
{
    long long ans = 0;
    long long x = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans += __ctoi(s[i]) * x;
        x *= 26;
    }

    return ans;
}

string solution(long long n, vector<string> bans)
{
    vector<long long> banned;
    banned.reserve(bans.size());
    for (auto b : bans)
    {
        banned.push_back(__stoi(b));
    }
    sort(banned.begin(), banned.end());
    banned.erase(unique(banned.begin(), banned.end()), banned.end());

    string answer = "";

    int strlen = bans.size();
    int cnt = 0;
    long long target;

    cnt = int(upper_bound(banned.begin(), banned.end(), n + cnt) - banned.begin());

    // string answer;

    while (target > 26)
    {
        // cout << target % 26 << " ";
        answer.push_back((__itoc((target % 26))));
        target /= 26;
        // cout << target << " ";
    }
    answer.push_back(__itoc((target)));
    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> bans = {"gqk", "kdn", "jxj", "jxi", "fug", "jxg", "ewq", "len", "bhc"};

    cout << solution(n, bans);

    return 0;
}