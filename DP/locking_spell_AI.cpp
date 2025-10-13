
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
// a=1, b=2, ..., z=26 (1-기반)
static inline int ctoi(char c) { return int(c - 'a') + 1; }
static inline char itoc(int x) { return char('a' + (x - 1)); }

// 1-기반 26진수 문자열 -> 정수
static long long str_to_num(const string &s)
{
    long long ans = 0;
    for (char c : s)
    {
        ans = ans * 26 + ctoi(c);
    }
    return ans;
}

// 1-기반 26진수 정수 -> 문자열 (엑셀 스타일)
static string num_to_str(long long t)
{
    string out;
    do
    {
        int r = int((t - 1) % 26);
        out.push_back(char('a' + r));
        t = (t - 1) / 26;
    } while (t > 0);
    reverse(out.begin(), out.end());
    return out;
}

string solution(long long n, vector<string> bans)
{
    // 1) bans를 숫자로 변환
    vector<long long> banned;
    banned.reserve(bans.size());
    for (const auto &s : bans)
    {
        banned.push_back(str_to_num(s));
    }
    // 2) 정렬 + 중복 제거
    sort(banned.begin(), banned.end());
    banned.erase(unique(banned.begin(), banned.end()), banned.end());

    // 보조: x 이하 금지 개수
    auto count_leq = [&](long long x) -> long long
    {
        return upper_bound(banned.begin(), banned.end(), x) - banned.begin();
    };

    // 3) 고정점 이진 탐색: x = n + count_leq(x)를 만족하는 최소 x
    // 상한 추정: n + banned.size() + 몇 자리 여유
    long long lo = 1, hi = max(1LL, n + (long long)banned.size() + 64);
    while (lo < hi)
    {
        long long mid = lo + (hi - lo) / 2;
        long long fx = n + count_leq(mid);
        if (fx <= mid)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    long long target = lo; // 최소 고정점

    // 4) 숫자를 1-기반 26진 문자열로 변환
    return num_to_str(target); // [web:35][web:31]
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<string> bans = {"gqk", "kdn", "jxj", "jxi", "fug", "jxg", "ewq", "len", "bhc"};
    cout << solution(n, bans) << "\n";
}