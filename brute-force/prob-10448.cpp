#include <iostream>
#include <algorithm>

using namespace std;

int a[45], check[1001];
int main()
{
    for (int i = 1; i <= 44; i++)
        a[i] = (i) * (i + 1) / 2;

    for (int x = 1; x <= 44; x++)
    {
        for (int y = 1; y <= 44; y++)
        {
            for (int z = 1; z <= 44; z++)
            {
                int t = a[x] + a[y] + a[z];
                if (t <= 1000)
                    check[t] = 1;
            }
        }
    }

    int n;
    scanf("%d", &n);
    while (n--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", check[k]);
    }
}