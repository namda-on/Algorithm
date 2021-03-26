#include <iostream>
#include <algorithm>

using namespace std;

int a[1001][1001];

int go(int n, int r)
{
    if (n == 1)
        return 1;
    if (r == 0 || r == n)
        return 1;
    if (a[n][r] != -1)
        return a[n][r];
    a[n][r] = (go(n - 1, r) + go(n - 1, r - 1)) % 10007;
    return a[n][r];
}

int main()
{
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            a[i][j] = -1;
        }
    }
    int n, r;
    scanf("%d%d", &n, &r);
    printf("%d", go(n, r));
}