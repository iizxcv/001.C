#include <iostream>
#include <vector>
#include <queue>

#define WCAP(x) ((x) << 10)
#define WDECAP(x) ((x) >> 10)
#define FINDGH(X) (static_cast<unsigned>(X) & 0x2FFu)
#define default_val 1001
using namespace std;

// 교차로(v), 도로(e), 목적지 후보의 개수

// s,g,h 예술가 출발지, g != h g,h(예술가들이 지나간 도로)
// a,b = vertex c = distance
// 출발지와 같지 않은 목적지

// n^2 복잡도는 기본일 거 같음
// 재귀나 스텍을 이용한 반복문으로 타고타고가면서 목적지 까지의 최단경로를 구해야 함
/* map 자료구조 기반으로  간선 정보(V,E)를 추가하고 간선 정보가 0이 아니면 찾게 할까??
무조건 g,h 를 지나는 경로여야 됨. 이를 확인하기 위해서 각 최단경로를 값만 저장하는게 아닌
목적지V,Cost) 순으로 이뤄져야 하지 않음?
글로벌 큐(path)하나 만들어

update_path(nodes,목적지V,현재V,depth)

    int cost;
    int nodes_size = nodes.size();
        if((현재V == g || i == h) && (현재V == h || i == g))
        {cost = WCAP(nodes[현재V][목적지V]);}
        else{cost = nodes[현재V][목적지V];}

    if(depth < nodes_size)
    for(int i = 0; nodes_size)
        if(현재v != i && cost > nodes[현재v][i])
        cost += update_path(nodes, 목적지V, i);


 */

void update_path(vector<vector<int>> &paco, vector<int> &dist, int start)
{
    int N = paco.size() - 1;

    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({-dist[start], start});

    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for (int i = 1; i < N + 1; i++)
        {
            if (i != cur_node)
            {
                int nxt_dist = cur_dist + paco[cur_node][i];

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
        int gh = 0;
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, default_val));

        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            if ((a == g && b == h) || (a == h && b == g))
            {
                graph[a][b] = graph[b][a] = 1;
                gh = d;
            }
            // {
            //     graph[a][b] = graph[b][a] = d;
            // }
            // else
            // {
            else
            {
                graph[a][b] = graph[b][a] = d * 10;
            }
            // }
        }
        vector<int> dist(n + 1, default_val);
        update_path(graph, dist, s);

        for (int i = 0; i < t; i++)
        {
            int d1;
            cin >> d1;
            dist[d1] /= 10;
            dist[d1] += gh;
            cout << dist[d1] << " ";
        }
    }

    return 0;
}
