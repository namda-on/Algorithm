#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n, c;

bool cmp(int a, int b)
{
    return a < b;
}

bool isPossible(int m)
{
    int cur = v[0];
    int total = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] - cur >= m)
        {
            cur = v[i];
            total++;
        }
    }
    return total >= c;
}

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);

    int start = 1;
    int end = v[n - 1] - v[0];

    while (start <= end)
    {
        int l = (start + end) / 2;
        if (isPossible(l))
            start = l + 1;
        else
            end = l - 1;
    }
    printf("%d", end);
}