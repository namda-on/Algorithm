#include <iostream>
#include <algorithm>

using namespace std;

int a[1000001];

int main()
{
    for (int i = 2; i <= 1000000; i++)
        a[i] = 1;

    for (int i = 0; i <= 1000000; i++)
    {
        if (!a[i])
            continue;
        for (int j = 2 * i; j <= 1000000; j += i)
        {
            a[j] = 0;
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = n; i <= m; i++)
    {
        if (a[i])
            printf("%d\n", i);
    }
}