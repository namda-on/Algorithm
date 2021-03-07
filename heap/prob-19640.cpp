#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Waiter
{
    int workday;
    int hurry;
    int row;
    bool isDeka;
};

struct cmp
{
    bool operator()(Waiter w1, Waiter w2)
    {
        if (w1.workday == w2.workday && w1.hurry == w2.hurry)
            return w1.row > w2.row;
        if (w1.workday == w2.workday)
            return w1.hurry < w2.hurry;
        return w1.workday < w2.workday;
    }
};

vector<queue<Waiter> > v;

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        queue<Waiter> line;
        v.push_back(line);
    }
    for (int i = 0; i < n; i++)
    {
        int d, h;
        scanf("%d%d", &d, &h);
        bool deka = i == k;
        Waiter w = {d, h, i % m, deka};
        v[i % m].push(w);
    }

    priority_queue<Waiter, vector<Waiter>, cmp> pq;

    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        if (v[i].empty())
            continue;
        pq.push(v[i].front());
        v[i].pop();
    }
    while (true)
    {
        Waiter top = pq.top();
        pq.pop();
        if (top.isDeka)
            break;
        answer++;
        if (!v[top.row].empty())
        {
            pq.push(v[top.row].front());
            v[top.row].pop();
        }
    }
    printf("%d", answer);
}