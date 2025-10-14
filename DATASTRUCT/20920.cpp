#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

struct Word
{
    string s;
    int len;
    int cnt;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // cnt, len, 사전순
    vector<Word> words(n);

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a.size() >= m)
        {
            words.push_back({a, (int)a.size(), 1});
        }
    }
    sort(words.begin(), words.end(), [](const Word &a, const Word &b)
         {
        if (a.cnt != b.cnt)
            return a.cnt > b.cnt;
        if (a.len != b.len)
            return a.len > b.len;
        
        return a.s < b.s; });

    for (auto ans : words)
    {
        cout << ans.s << "\n";
    }
}
