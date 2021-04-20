#include <iostream>
#include <algorithm>

using namespace std;

int h[100];

int double_sum(int L)
{
    return L * (L + 1) * (2 * L + 1) / 6;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
        sum += h[i] + 1;
    }

    if (sum >= m)
    {
        printf("0");
        return 0;
    }

    int l = (m - sum) / (n + 1);
    int remain = (m - sum) % (n + 1);

    int depression = double_sum(l) * (n + 1 - remain) + double_sum(l + 1) * remain;
    printf("%d", depression);
}