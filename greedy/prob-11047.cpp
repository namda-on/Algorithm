#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);

    int total = 0;
    int num = 0;
    int i = 0;
    while (total != k && i < v.size())
    {
        if (v[i] <= k - total)
        {
            int count = (k - total) / v[i];
            num += count;
            total += v[i] * count;
        }
        i++;
    }
    printf("%d", num);
}