#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", gcd(x, y));
    printf("%d\n", lcm(x, y));
}