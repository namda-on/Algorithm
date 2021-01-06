#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[10001];
int main()
{
    int n;
    long long m;
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long answer = 0;
    int low = 0, high = 0;
    int sum = a[0];

    while (low <= high && high < n) {
        if (sum < m)
            sum += a[++high];
        else if (sum == m) {
            answer++;
            sum += a[++high];
        }
        else if (sum > m) {
            sum -= a[low++];
            if (low > high && low < n)
            {
                high = low;
                sum = a[low];
            }
        }
    }
    printf("%lld", answer);

}