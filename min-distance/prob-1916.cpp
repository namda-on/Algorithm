#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INFINTE 100000000

int n, m;
vector<pair<int, int>> v[1001];
int dist[1001];
bool check[1001];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        dist[i] = INFINTE;

    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        scanf("%d%d%d", &start, &end, &cost);
        v[start].push_back(make_pair(end, cost));
    }
    int s, d;
    scanf("%d%d", &s, &d);
    dist[s] = 0;

    for (int i = 1; i <= n; i++)
    {
        int small = INFINTE;
        int cur = 0;
        for (int j = 1; j <= n; j++)
        {

            if (!check[j] && dist[j] < small)
            {
                small = dist[j];
                cur = j;
            }
        }
        for (pair<int, int> next : v[cur])
        {
            dist[next.first] = min(dist[cur] + next.second, dist[next.first]);
        }
        check[cur] = true;
    }
    printf("%d\n", dist[d]);
}