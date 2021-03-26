#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    int r = 0;
    while (n--)
    {
        int temp;
        scanf("%d", &temp);
        if (is_prime(temp))
            r++;
    }
    printf("%d", r);
}