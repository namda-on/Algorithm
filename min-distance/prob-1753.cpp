#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INFINTE 100000000

int n, m;
vector<pair<int, int>> v[20001];
int dist[20001];
bool check[20001];
priority_queue<pair<int, int>> q;

int main()
{
    scanf("%d%d", &n, &m);
    int s;
    scanf("%d", &s);

    for (int i = 0; i <= n; i++)
        dist[i] = INFINTE;

    dist[s] = 0;

    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        scanf("%d%d%d", &start, &end, &cost);
        v[start].push_back(make_pair(end, cost));
    }

    q.push(make_pair(0, s));

    while (!q.empty())
    {
        int cur = q.top().second;
        q.pop();
        if (check[cur])
            continue;

        for (pair<int, int> next : v[cur])
        {
            dist[next.first] = min(dist[cur] + next.second, dist[next.first]);
            q.push(make_pair(-dist[next.first], next.first));
        }
        check[cur] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INFINTE)
            puts("INF");
        else
            printf("%d\n", dist[i]);
    }
}