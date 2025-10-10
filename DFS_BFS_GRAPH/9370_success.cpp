#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define default_val 1e9
using namespace std;

void update_path(vector<vector<unsigned int>> &paco, vector<unsigned int> &dist, int start)
{
    int N = paco.size() - 1;

    priority_queue<pair<unsigned int, unsigned int>> pq;

    dist[start] = 0;
    pq.push({-dist[start], start});

    while (!pq.empty())
    {
        unsigned int cur_dist = -pq.top().first;
        unsigned int cur_node = pq.top().second;
        pq.pop();
        if (cur_dist > dist[cur_node])
        {
            continue;
        }
        for (int i = 1; i < N + 1; i++)
        {
            if (i != cur_node && paco[cur_node][i] != 0)
            {
                unsigned int nxt_dist = cur_dist + paco[cur_node][i];

                if (nxt_dist < dist[i])
                {
                    dist[i] = nxt_dist;
                    pq.push({-nxt_dist, i});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (T; T > 0; T--)
    {
        int n, m, t;
        int s, g, h;
        cin >> n >> m >> t; // 교차로,도로, 목적지 후보
        cin >> s >> g >> h; // 예술가들의 출발지, 거쳐야하는 도로
        int gh = default_val;
        vector<vector<unsigned int>> graph(n + 1, vector<unsigned int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;

            graph[a][b] = graph[b][a] = d;
            if ((a == g && b == h) || (a == h && b == g))
            {
                gh = d;
            }
        }
        vector<unsigned int> dist_s(n + 1, default_val);
        vector<unsigned int> dist_g(n + 1, default_val);
        vector<unsigned int> dist_h(n + 1, default_val);
        update_path(graph, dist_s, s);
        update_path(graph, dist_g, g);
        update_path(graph, dist_h, h);
        vector<unsigned int> ans;
        for (int i = 0; i < t; i++)
        {

            int d1;
            cin >> d1;
            // dist[d1];
            if (dist_s[d1] == dist_s[g] + gh + dist_h[d1] || dist_s[d1] == dist_s[h] + gh + dist_g[d1])
            {
                ans.push_back(d1);
            }
        }
        sort(ans.begin(), ans.end());
        for (auto a : ans)
        {
            cout << a << " ";
        }
        cout << "\n";
    }

    return 0;
}
